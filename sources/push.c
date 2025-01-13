/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/12 21:16:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_stack *a, t_stack *b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (b->size > 0)
	{
		head_a = a->head;
		head_b = b->head;
		b->head = b->head->next;
		a->head = head_b;
		a->head->next = head_a;
		a->size++;
		b->size--;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
}
