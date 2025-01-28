/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:04:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Checks if the stack is sorted.
 *
 * This function checks if the stack is sorted.
 *
 * @param stack The stack.
 * @return true if the stack is sorted, false otherwise.
 */
bool	is_sorted(t_stack *stack)
{
	t_node	*node;
	int		index;

	if (!stack || stack->size == 0)
		return (true);
	index = 0;
	node = stack->top;
	while (index < stack->size - 1)
	{
		if (node->nbr > node->next->nbr)
			return (false);
		node = node->next;
		index++;
	}
	return (true);
}

/**
 * @brief Updates the index in the stack.
 *
 * This function updates the index in the stack.
 *
 * @param stack The stack.
 */
void	update_index_in_stack(t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack->top;
	while (index < stack->size)
	{
		node->above_middle = (index <= stack->size / 2);
		node->index = index;
		node = node->next;
		index++;
	}
}

/**
 * @brief Calculates the cost to push a node to stack b.
 *
 * This function calculates the cost to push a node to stack b.
 *
 * @param node The node.
 * @param stacks The stacks.
 * @return The cost to push the node to stack b.
 */
int	calculate_cost_to_push_node_to_stack_b(t_node *node, t_stacks *stacks)
{
	int	cost_to_push;

	cost_to_push = node->index;
	if (!node->above_middle)
		cost_to_push = stacks->a.size - node->index;
	if (node->target_node->above_middle)
		cost_to_push += node->target_node->index;
	else
		cost_to_push += stacks->b.size - node->target_node->index;
	return (cost_to_push);
}

/**
 * @brief Sets the target node for each element in stack a.
 *
 * This function sets the target node for each element in stack a.
 *
 * @param stacks The stacks.
 */
void	set_target_node_for_each_element_in_stack_a(t_stacks *stacks)
{
	int		index;
	t_node	*node;
	t_node	*target_node;

	index = 0;
	node = stacks->a.top;
	while (index < stacks->a.size)
	{
		node->index = index;
		target_node = find_the_smallest_closest_number(node, &stacks->b);
		if (target_node == NULL)
			target_node = find_the_biggest_number(&stacks->b);
		node->target_node = target_node;
		node = node->next;
		index++;
	}
}

/**
 * @brief Frees the mallocs.
 *
 * This function frees the mallocs.
 *
 * @param stacks The stacks.
 * @param argc The number of arguments.
 * @param args The arguments.
 * @param args_len The length of the arguments.
 */
void	free_mallocs(t_stacks *stacks, int argc, char **args, int args_len)
{
	int		index;
	t_node	*node;

	index = 0;
	while (index < stacks->a.size)
	{
		node = stacks->a.top;
		stacks->a.top = node->next;
		free(node);
		index++;
	}
	if (argc == 2)
	{
		index = 0;
		while (index < args_len)
		{
			free(args[index]);
			index++;
		}
		free(args);
	}
}
