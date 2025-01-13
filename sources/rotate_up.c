/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/12 21:22:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	rotate_up(t_stack *stack)
{
	t_list	*head;
	t_list	*last;

	if (stack->size > 1)
	{
		head = stack->head;
		last = ft_lstlast(head);
		stack->head = head->next;
		head->next = NULL;
		last->next = head;
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
