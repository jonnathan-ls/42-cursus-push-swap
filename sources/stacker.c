/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:16:48 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Initializes the properties of the stacks.
 *
 * This function initializes the base and top pointers of the stacks to NULL,
 * and sets the size of the stacks to 0.
 *
 * @param stacks Pointer to the stacks structure to initialize.
 */
static void	init_properties(t_stacks *stacks)
{
	stacks->a.base = NULL;
	stacks->b.base = NULL;
	stacks->a.top = NULL;
	stacks->b.top = NULL;
	stacks->a.size = 0;
	stacks->b.size = 0;
}

/**
 * @brief Creates a new node with the given value.
 *
 * This function allocates memory for a new node, initializes its value with the
 * given integer, and sets its next and prev pointers to NULL.
 *
 * @param value The integer value to store in the new node.
 * @return Pointer to the newly created node, or NULL if memory allocation fails.
 */
static t_node	*new_node(int number)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nbr = number;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
 * @brief Pushes a node onto the stack.
 *
 * This function pushes a node onto the top of the stack. If the stack is empty,
 * the node becomes both the top and the base of the stack. Otherwise, the node
 * is added to the top of the stack and the links are updated accordingly.
 *
 * @param stack Pointer to the stack to push the node onto.
 * @param node Pointer to the node to push onto the stack.
 */
static void	push_node_to_stack(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->top = node;
		stack->top->next = node;
		stack->top->prev = node;
		stack->base = node;
		stack->base->next = node;
		stack->base->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->base;
		stack->top->prev = node;
		stack->base->next = node;
		stack->top = node;
	}
}

/**
 * @brief Initializes the stacks with the arguments given.
 *
 * This function initializes the stacks with the arguments provided. It converts
 * the arguments to integers, creates nodes for each integer, and pushes them
 * onto the stack. The stack is initialized in reverse order of the arguments.
 *
 * @param stacks Pointer to the stacks structure to initialize.
 * @param size The number of arguments.
 * @param args The arguments to initialize the stacks with.
 * @return true if the stacks were successfully initialized, false otherwise.
 */
bool	init_stacks(t_stacks *stacks,	int size, char **args)
{
	int		number;
	t_node	*node;
	t_node	*previous_node;

	previous_node = NULL;
	init_properties(stacks);
	while (size > 0)
	{
		number = ft_atoi(args[size - 1]);
		node = new_node(number);
		if (!node)
			return (false);
		node->index = size - 1;
		if (previous_node != NULL)
			node->prev = previous_node;
		push_node_to_stack(&stacks->a, node);
		previous_node = node;
		stacks->a.size++;
		size--;
	}
	stacks->a.base->next = stacks->a.top;
	stacks->a.top->prev = stacks->a.base;
	return (true);
}
