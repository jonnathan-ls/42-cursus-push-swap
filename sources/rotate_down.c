/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/18 22:23:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rotate_down(t_stack *stack)
{
	t_node	*top;
	t_node	*base;
	t_node	*previous_base;

	previous_base = NULL;
	if (stack->size > 1)
	{
		top = stack->top;
		base = top;
		while (base->next)
		{
			if (previous_base && base->next->next == NULL)
				previous_base = base;
			base = base->next;
		}
		base->next = top;
		stack->top = base;
		previous_base->next = NULL;
	}
}

void	rra(t_stack *a)
{
	rotate_down(a);
}

void	rrb(t_stack *b)
{
	rotate_down(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
}
