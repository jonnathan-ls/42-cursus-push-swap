/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:00:01 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Rotates the stack down.
 *
 * This function rotates the stack down.
 *
 * @param stack The stack.
 */
static void	rotate_down(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->prev;
		stack->base = stack->base->prev;
	}
}

/**
 * @brief Rotates the stack a down.
 *
 * This function rotates the stack a down.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	rra(t_stacks *stacks, bool print)
{
	rotate_down(&stacks->a);
	if (print)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

/**
 * @brief Rotates the stack b down.
 *
 * This function rotates the stack b down.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	rrb(t_stacks	*stacks, bool print)
{
	rotate_down(&stacks->b);
	if (print)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

/**
 * @brief Rotates the stack a and b down.
 *
 * This function rotates the stack a and b down.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	rrr(t_stacks *stacks, bool print)
{
	rotate_down(&stacks->a);
	rotate_down(&stacks->b);
	if (print)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
