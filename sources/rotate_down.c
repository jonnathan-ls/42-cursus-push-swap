/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/12 21:16:25 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rotate_down(t_stack *stack)
{
	t_list	*head;
	t_list	*last;
	t_list	*before_last;

	before_last = NULL;
	if (stack->size > 1)
	{
		head = stack->head;
		last = head;
		while (last->next)
		{
			if (before_last && last->next->next == NULL)
				before_last = last;
			last = last->next;
		}
		last->next = head;
		stack->head = last;
		before_last->next = NULL;
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
