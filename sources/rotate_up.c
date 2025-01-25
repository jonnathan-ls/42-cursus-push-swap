/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 16:29:11 by jlacerda         ###   ########.fr       */
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

void	ra(t_env	*env)
{
	rotate_up(&env->a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_env	*env)
{
	rotate_up(&env->b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_env *env)
{
	rotate_up(&env->a);
	rotate_up(&env->b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
