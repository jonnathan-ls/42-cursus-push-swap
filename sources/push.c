/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/26 21:45:03 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_stack(t_stack *to, t_node *new_node)
{
	to->top = new_node;
	to->base = new_node;
	new_node->next = new_node;
	new_node->prev = new_node;
}

static void	update_stack(t_stack *to, t_node *new_node)
{
	new_node->next = to->top;
	new_node->prev = to->base;
	to->top->prev = new_node;
	to->base->next = new_node;
	to->top = new_node;
}

static void	push(t_stack *from, t_stack *to)
{
	t_node	*new_node;

	if (from->size > 0)
	{
		new_node = from->top;
		from->top = from->top->next;
		from->top->prev = from->base;
		from->base->next = from->top;
		if (to->size == 0)
			init_stack(to, new_node);
		else
			update_stack(to, new_node);
		from->size--;
		to->size++;
	}
}

void	pa(t_stacks *stacks, bool print)
{
	push(&stacks->b, &stacks->a);
	if (print)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stacks *stacks, bool print)
{
	push(&stacks->a, &stacks->b);
	if (print)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}
