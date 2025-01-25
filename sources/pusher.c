/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 18:29:33 by jlacerda         ###   ########.fr       */
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
	t_env *env, t_node *node, int *movements_in_a, int *movements_in_b)
{
	while (*movements_in_a > 0 && *movements_in_b > 0)
	{
		if (node->above_middle && node->target_node->above_middle)
			rr(env);
		else if (!node->above_middle && !node->target_node->above_middle)
			rrr(env);
		else
			break ;
		(*movements_in_a)--;
		(*movements_in_b)--;
	}
}

static void	execute_remaining_movements(t_env *env, int movements,
	int above_middle, void (*move_up)(t_env *), void (*move_down)(t_env *))
{
	while (movements-- > 0)
	{
		if (above_middle)
			move_up(env);
		else
			move_down(env);
	}
}

void	push_node_in_stack_b(t_env *env, t_node *node)
{
	int	movements_in_a;
	int	movements_in_b;

	movements_in_a = calculate_movements(
			node->index, env->a.size, node->above_middle);
	movements_in_b = calculate_movements(node->target_node->index,
			env->b.size, node->target_node->above_middle);
	execute_simultaneous_movements(env,
		node, &movements_in_a, &movements_in_b);
	execute_remaining_movements(env,
		movements_in_a, node->above_middle, ra, rra);
	execute_remaining_movements(env,
		movements_in_b, node->target_node->above_middle, rb, rrb);
	pb(env);
}

void	push_node_in_stack_a(t_env *env, t_node *node)
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
