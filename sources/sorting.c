/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 20:21:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	push_elements_to_stack_b(t_stacks *stacks)
{
	int		size;
	t_node	*node;

	size = stacks->a.size;
	if (size-- > 3 && !is_sorted(&stacks->a))
		pb(stacks);
	if (size-- > 3 && !is_sorted(&stacks->a))
		pb(stacks);
	while (size-- > 3 && !is_sorted(&stacks->a))
	{
		update_index_in_stack(&stacks->a);
		update_index_in_stack(&stacks->b);
		set_target_node_for_each_element_in_stack_a(stacks);
		node = find_node_to_push_in_stack_b(stacks);
		push_node_in_stack_b(stacks, node);
	}
}

static void	push_elements_back_to_stack_a(t_stacks *stacks)
{
	t_node	*node;

	while (stacks->b.size > 0)
	{
		update_index_in_stack(&stacks->a);
		update_index_in_stack(&stacks->b);
		node = find_the_biggest_closest_number(stacks->b.top, &stacks->a);
		if (node == NULL)
			node = find_the_smallest_number(&stacks->a);
		push_node_in_stack_a(stacks, node);
	}
}

static void	adjust_stack_a_putting_in_order(t_stacks *stacks)
{
	t_node	*smallest_value;

	update_index_in_stack(&stacks->a);
	smallest_value = find_the_smallest_number(&stacks->a);
	if (smallest_value->above_middle)
		while (stacks->a.top != smallest_value)
			ra(stacks);
	else
		while (stacks->a.top != smallest_value)
			rra(stacks);
}

void	sort_three(t_stacks *stacks)
{
	t_node	*biggest_node;

	biggest_node = find_the_biggest_number(&stacks->a);
	if (biggest_node == stacks->a.top)
		ra(stacks);
	else if (biggest_node == stacks->a.top->next)
		rra(stacks);
	if (stacks->a.top->nbr > stacks->a.top->next->nbr)
		sa(stacks);
}

void	sort_big(t_stacks *stacks)
{
	push_elements_to_stack_b(stacks);
	sort_three(stacks);
	push_elements_back_to_stack_a(stacks);
	adjust_stack_a_putting_in_order(stacks);
}
