/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/18 22:21:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*top_of_a;
	t_node	*top_of_b;

	if (to->size > 0)
	{
		top_of_a = from->top;
		top_of_b = to->top;
		to->top = to->top->next;
		from->top = top_of_b;
		from->top->next = top_of_a;
		from->size++;
		to->size--;
	}
}

void	pa(t_env *env)
{
	push(&(*env).b, &(*env).a);
}

void	pb(t_env *env)
{
	push(&(*env).a, &(*env).b);
}
