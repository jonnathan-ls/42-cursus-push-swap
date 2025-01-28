/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:00:50 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Rotates the stack up.
 *
 * This function rotates the stack up.
 *
 * @param stack The stack.
 */
static void	rotate_up(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->next;
		stack->base = stack->base->next;
	}
}

/**
 * @brief Rotates the stack a up.
 *
 * This function rotates the stack a up.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	ra(t_stacks	*stacks, bool print)
{
	rotate_up(&stacks->a);
	if (print)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

/**
 * @brief Rotates the stack b up.
 *
 * This function rotates the stack b up.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	rb(t_stacks	*stacks, bool print)
{
	rotate_up(&stacks->b);
	if (print)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

/**
 * @brief Rotates the stack a and b up.
 *
 * This function rotates the stack a and b up.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	rr(t_stacks *stacks, bool print)
{
	rotate_up(&stacks->a);
	rotate_up(&stacks->b);
	if (print)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
