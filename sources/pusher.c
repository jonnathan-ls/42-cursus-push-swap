/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/26 21:57:43 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_movements(int index, int size, int above_middle)
{
	if (above_middle)
		return (index);
	else
		return (size - index);
}

static void	execute_simultaneous_movements(
	t_stacks *stacks, t_node *node, int *movements_of_a, int *movements_of_b)
{
	while (*movements_of_a > 0 && *movements_of_b > 0)
	{
		if (node->above_middle && node->target_node->above_middle)
			rr(stacks, PRINT_OPT);
		else if (!node->above_middle && !node->target_node->above_middle)
			rrr(stacks, PRINT_OPT);
		else
			break ;
		(*movements_of_a)--;
		(*movements_of_b)--;
	}
}

void	push_node_in_stack_b(t_stacks *stacks, t_node *node)
{
	int	movements_of_a;
	int	movements_of_b;

	movements_of_a = calculate_movements(
			node->index, stacks->a.size, node->above_middle);
	movements_of_b = calculate_movements(node->target_node->index,
			stacks->b.size, node->target_node->above_middle);
	execute_simultaneous_movements(stacks,
		node, &movements_of_a, &movements_of_b);
	while (movements_of_a-- > 0)
	{
		if (node->above_middle)
			ra(stacks, PRINT_OPT);
		else
			rra(stacks, PRINT_OPT);
	}
	while (movements_of_b-- > 0)
	{
		if (node->target_node->above_middle)
			rb(stacks, PRINT_OPT);
		else
			rrb(stacks, PRINT_OPT);
	}
	pb(stacks, PRINT_OPT);
}

void	push_node_in_stack_a(t_stacks *stacks, t_node *node)
{
	int	movements_of_a;

	if (node->above_middle)
		movements_of_a = node->index;
	else
		movements_of_a = stacks->a.size - node->index;
	while (movements_of_a-- > 0)
	{
		if (node->above_middle)
			ra(stacks, PRINT_OPT);
		else
			rra(stacks, PRINT_OPT);
	}
	pa(stacks, PRINT_OPT);
}
