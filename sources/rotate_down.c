/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 20:21:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate_down(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->prev;
		stack->base = stack->base->prev;
	}
}

void	rra(t_stacks *stacks)
{
	rotate_down(&stacks->a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stacks	*stacks)
{
	rotate_down(&stacks->b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stacks *stacks)
{
	rotate_down(&stacks->a);
	rotate_down(&stacks->b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
