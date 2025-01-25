/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 16:28:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->size > 1)
	{
		temp_node = stack->top;
		stack->top = stack->top->next;
		stack->top->prev = stack->base;
		stack->base->next = stack->top;
		temp_node->next = stack->top->next;
		stack->top->next->prev = temp_node;
		stack->top->next = temp_node;
		temp_node->prev = stack->top;
		if (stack->size == 2)
			stack->base = stack->top->next;
		else if (stack->size == 3)
			stack->base->prev = temp_node;
	}
}

void	sa(t_env	*env)
{
	swap(&env->a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_env	*env)
{
	swap(&env->b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_env	*env)
{
	swap(&env->a);
	swap(&env->b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
