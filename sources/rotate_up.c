/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/18 23:01:48 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rotate_up(t_stack *stack)
{
	t_node	*top;

	if (stack->size > 1)
	{
		top = stack->top;
		stack->top = stack->top->next;
		stack->base = top;
	}
}

void	ra(t_stack *a)
{
	rotate_up(a);
}

void	rb(t_stack *b)
{
	rotate_up(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
}
