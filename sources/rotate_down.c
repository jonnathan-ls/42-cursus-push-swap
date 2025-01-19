/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/22 21:23:21 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// rotaciona	a pilha para baixo
// top passa a ser o proximo
// base	passa a ser o top
// top prev	passa a ser o base
// base	next passa a ser o top
static void	rotate_down(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->prev;
		stack->base = stack->base->prev;
	}
}

void	rra(t_env *env)
{
	rotate_down(&env->a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_env	*env)
{
	rotate_down(&env->b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_env *env)
{
	rotate_down(&env->a);
	rotate_down(&env->b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
