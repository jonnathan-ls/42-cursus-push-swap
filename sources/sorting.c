/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 19:42:33 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	push_elements_to_stack_b(t_env *env)
{
	int		size;
	t_node	*node;

	size = env->a.size;
	if (size-- > 3 && !is_sorted(&env->a))
		pb(env);
	if (size-- > 3 && !is_sorted(&env->a))
		pb(env);
	while (size-- > 3 && !is_sorted(&env->a))
	{
		update_index_in_stack(&env->a);
		update_index_in_stack(&env->b);
		set_target_node_for_each_element_in_stack_a(env);
		node = find_node_to_push_in_stack_b(env);
		push_node_in_stack_b(env, node);
	}
}

static void	push_elements_back_to_stack_a(t_env *env)
{
	t_node	*node;

	while (env->b.size > 0)
	{
		update_index_in_stack(&env->a);
		update_index_in_stack(&env->b);
		node = find_the_biggest_closest_number(env->b.top, &env->a);
		if (node == NULL)
			node = find_the_smallest_number(&env->a);
		push_node_in_stack_a(env, node);
	}
}

static void	adjust_stack_a_putting_in_order(t_env *env)
{
	t_node	*smallest_value;

	update_index_in_stack(&env->a);
	smallest_value = find_the_smallest_number(&env->a);
	if (smallest_value->index <= env->a.size / 2)
		while (env->a.top != smallest_value)
			ra(env);
	else
		while (env->a.top != smallest_value)
			rra(env);
}

void	sort_three(t_env *env)
{
	t_node	*biggest_node;

	biggest_node = find_the_biggest_number(&env->a);
	if (biggest_node == env->a.top)
		ra(env);
	else if (biggest_node == env->a.top->next)
		rra(env);
	if (env->a.top->nbr > env->a.top->next->nbr)
		sa(env);
}

void	sort_big(t_env *env)
{
	push_elements_to_stack_b(env);
	sort_three(env);
	push_elements_back_to_stack_a(env);
	adjust_stack_a_putting_in_order(env);
}
