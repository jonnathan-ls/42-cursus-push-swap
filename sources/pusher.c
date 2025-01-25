/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 20:22:37 by jlacerda         ###   ########.fr       */
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
			rr(stacks);
		else if (!node->above_middle && !node->target_node->above_middle)
			rrr(stacks);
		else
			break ;
		(*movements_of_a)--;
		(*movements_of_b)--;
	}
}

static void	execute_remaining_movements(
	t_stacks *stacks, int movements, int above_middle,
	void (*move_up)(t_stacks *), void (*move_down)(t_stacks *))
{
	while (movements-- > 0)
	{
		if (above_middle)
			move_up(stacks);
		else
			move_down(stacks);
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
	execute_remaining_movements(stacks,
		movements_of_a, node->above_middle, ra, rra);
	execute_remaining_movements(stacks,
		movements_of_b, node->target_node->above_middle, rb, rrb);
	pb(stacks);
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
			ra(stacks);
		else
			rra(stacks);
	}
	pa(stacks);
}
