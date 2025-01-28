/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:16:19 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Swaps the first two elements at the top of the stack.
 *
 * This function swaps the first two elements at the top of the given stack. If
 * the stack has fewer than two elements, the function does nothing.
 *
 * @param stack Pointer to the stack on which to perform the swap.
 */
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

/**
 * @brief Swaps the top two elements of stack a.
 *
 * This function swaps the top two elements of stack a.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	sa(t_stacks	*stacks, bool print)
{
	swap(&stacks->a);
	if (print)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

/**
 * @brief Swaps the top two elements of stack b.
 *
 * This function swaps the top two elements of stack b.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	sb(t_stacks	*stacks, bool print)
{
	swap(&stacks->b);
	if (print)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

/**
 * @brief Swaps the top two elements of stack a and stack b.
 *
 * This function swaps the top two elements of stack a and stack b.
 *
 * @param stacks The stacks.
 * @param print Whether to print the operation.
 */
void	ss(t_stacks	*stacks, bool print)
{
	swap(&stacks->a);
	swap(&stacks->b);
	if (print)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}
