/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 19:40:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*node;
	int		index;

	if (!stack || stack->size == 0)
		return (true);
	index = 0;
	node = stack->top;
	while (index < stack->size - 1)
	{
		if (node->nbr > node->next->nbr)
			return (false);
		node = node->next;
		index++;
	}
	return (true);
}

void	update_index_in_stack(t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack->top;
	while (index < stack->size)
	{
		node->above_middle = (index <= stack->size / 2);
		node->index = index;
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

void	set_target_node_for_each_element_in_stack_a(t_env *env)
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

void	free_mallocs(t_env *env, int argc, char **args, int args_len)
{
	int		index;
	t_node	*node;

	index = 0;
	while (index < env->a.size)
	{
		node = env->a.top;
		env->a.top = node->next;
		free(node);
		index++;
	}
	if (argc == 2)
	{
		index = 0;
		while (index < args_len)
		{
			free(args[index]);
			index++;
		}
		free(args);
	}
}
