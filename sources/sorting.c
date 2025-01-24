/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/24 01:32:29 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_node	*find_the_smallest_closest_number(t_node *node, t_stack *stack)
{
	t_node	*closest_smaller_node;
	t_node	*temp_node;
	int		index;

	index = 0;
	temp_node = stack->top;
	closest_smaller_node = NULL;
	while (index < stack->size)
	{
		temp_node->index = index;
		if (temp_node->nbr < node->nbr)
		{
			if (closest_smaller_node == NULL
				|| temp_node->nbr > closest_smaller_node->nbr)
			{
				closest_smaller_node = temp_node;
				closest_smaller_node->index = index;
			}
		}
		temp_node = temp_node->next;
		index++;
	}
	return (closest_smaller_node);
}

static t_node	*find_the_biggest_closest_number(t_node *node, t_stack *stack)
{
	t_node	*closest_bigger_node;
	t_node	*temp_node;
	int		index;

	index = 0;
	temp_node = stack->top;
	closest_bigger_node = NULL;
	while (index < stack->size)
	{
		temp_node->index = index;
		if (temp_node->nbr > node->nbr)
		{
			if (closest_bigger_node == NULL
				|| temp_node->nbr < closest_bigger_node->nbr)
			{
				closest_bigger_node = temp_node;
				closest_bigger_node->index = index;
			}
		}
		temp_node = temp_node->next;
		index++;
	}
	return (closest_bigger_node);
}

void	set_target_nodes_in_a(t_env *env)
{
	int		index;
	t_node	*node;
	t_node	*target_node;

	index = 0;
	node = env->a.top;
	while (index < env->a.size)
	{
		node->index = index;
		target_node = find_the_smallest_closest_number(node, &env->b);
		if (target_node == NULL)
			target_node = find_the_biggest_number(&env->b);
		node->target_node = target_node;
		node = node->next;
		index++;
	}
}

int	calculate_cost_to_push_node_to_stack_b(t_node *node, t_env *env)
{
	int	cost_to_push;

	cost_to_push = node->index;
	if (!node->above_middle)
		cost_to_push = env->a.size - node->index;
	if (node->target_node->above_middle)
		cost_to_push += node->target_node->index;
	else
		cost_to_push += env->b.size - node->target_node->index;
	return (cost_to_push);
}

t_node	*find_node_to_push_in_stack_b(t_env *env)
{
	int		index;
	int		node_cost;
	t_node	*node;
	t_node	*cheapest_node;
	int		cheapest_cost;

	index = 0;
	cheapest_cost = 0;
	node = env->a.top;
	cheapest_node = NULL;
	while (index < env->a.size)
	{
		node->index = index;
		node_cost = calculate_cost_to_push_node_to_stack_b(node, env);
		if (cheapest_node == NULL || node_cost < cheapest_cost)
		{
			cheapest_node = node;
			cheapest_cost = node_cost;
			cheapest_node->index = index;
		}
		node = node->next;
		index++;
	}
	return (cheapest_node);
}

static void	push_node_in_stack_b(t_env *env, t_node *node)
{
	int	movements_in_a;
	int	movements_in_b;

	if (node->above_middle)
		movements_in_a = node->index;
	else
		movements_in_a = env->a.size - node->index;
	if (node->target_node->above_middle)
		movements_in_b = node->target_node->index;
	else
		movements_in_b = env->b.size - node->target_node->index;
	while (movements_in_a > 0 && movements_in_b > 0)
	{
		if (node->above_middle && node->target_node->above_middle)
			rr(env);
		else if (!node->above_middle && !node->target_node->above_middle)
			rrr(env);
		else
			break ;
		movements_in_a--;
		movements_in_b--;
	}
	while (movements_in_a-- > 0)
	{
		if (node->above_middle)
			ra(env);
		else
			rra(env);
	}
	while (movements_in_b-- > 0)
	{
		if (node->target_node->above_middle)
			rb(env);
		else
			rrb(env);
	}
	pb(env);
}

static void	push_node_in_stack_a(t_env *env, t_node *node)
{
	int	movements_in_a;

	if (node->above_middle)
		movements_in_a = node->index;
	else
		movements_in_a = env->a.size - node->index;
	while (movements_in_a-- > 0)
	{
		if (node->above_middle)
			ra(env);
		else
			rra(env);
	}
	pa(env);
}

void	sort_stack(t_env *env)
{
	int		size;
	t_node	*node;
	t_node	*smallest_value;

	size = env->a.size;
	if (size-- > 3 && !is_sorted(&env->a))
		pb(env);
	if (size-- > 3 && !is_sorted(&env->a))
		pb(env);
	while (size-- > 3 && !is_sorted(&env->a))
	{
		update_index_in_stack(&env->a);
		update_index_in_stack(&env->b);
		set_target_nodes_in_a(env);
		node = find_node_to_push_in_stack_b(env);
		push_node_in_stack_b(env, node);
	}
	sort_three(env);
	while (env->b.size > 0)
	{
		update_index_in_stack(&env->a);
		update_index_in_stack(&env->b);
		node = find_the_biggest_closest_number(env->b.top, &env->a);
		if (node == NULL)
			node = find_the_smallest_number(&env->a);
		push_node_in_stack_a(env, node);
	}
	update_index_in_stack(&env->a);
	smallest_value = find_the_smallest_number(&env->a);
	if (smallest_value->index <= env->a.size / 2)
		while (env->a.top != smallest_value)
			ra(env);
	else
		while (env->a.top != smallest_value)
			rra(env);
}
