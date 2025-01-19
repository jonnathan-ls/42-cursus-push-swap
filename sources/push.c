/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/22 22:08:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*new_node;

	if (from->size > 0)
	{
		new_node = from->top;
		from->top = from->top->next;
		from->top->prev = from->base;
		from->base->next = from->top;
		if (to->size == 0)
		{
			to->top = new_node;
			to->base = new_node;
			to->top->next = new_node;
			to->top->prev = new_node;
			to->base->next = new_node;
			to->base->prev = new_node;
		}
		else
		{
			new_node->next = to->top;
			new_node->prev = to->base;
			to->top->prev = new_node;
			to->base->next = new_node;
			to->top = new_node;
		}
	}
	from->size--;
	to->size++;
}

void	pa(t_env *env)
{
	push(&(*env).b, &(*env).a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_env *env)
{
	push(&(*env).a, &(*env).b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
