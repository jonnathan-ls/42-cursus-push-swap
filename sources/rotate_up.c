/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/26 21:44:03 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate_up(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->next;
		stack->base = stack->base->next;
	}
}

void	ra(t_stacks	*stacks, bool print)
{
	rotate_up(&stacks->a);
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stacks	*stacks, bool print)
{
	rotate_up(&stacks->b);
	if (print)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stacks *stacks, bool print)
{
	rotate_up(&stacks->a);
	rotate_up(&stacks->b);
	if (print)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
