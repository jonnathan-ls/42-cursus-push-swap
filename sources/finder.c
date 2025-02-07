/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:15:26 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the biggest number in a stack.
 *
 * This function iterates through the stack and finds the node with the largest
 * value. It returns the node with the largest value.
 *
 * @param stack Pointer to the stack to search.
 * @return Pointer to the node with the largest value.
 */
t_node	*find_the_biggest_number(t_stack *stack)
{
	int		index;
	t_node	*temp_node;
	t_node	*biggest_node;

	index = 0;
	temp_node = stack->top;
	biggest_node = temp_node;
	while (index < stack->size)
	{
		if (temp_node->nbr > biggest_node->nbr)
		{
			biggest_node = temp_node;
			biggest_node->index = index;
		}
		temp_node = temp_node->next;
		index++;
	}
	return (biggest_node);
}

/**
 * @brief Finds the smallest number in a stack.
 *
 * This function iterates through the stack and finds the node with the smallest
 * value. It returns the node with the smallest value.
 *
 * @param stack Pointer to the stack to search.
 * @return Pointer to the node with the smallest value.
 */
t_node	*find_the_smallest_number(t_stack *stack)
{
	int		index;
	t_node	*temp_node;
	t_node	*smallest_node;

	index = 0;
	temp_node = stack->top;
	smallest_node = temp_node;
	while (index < stack->size)
	{
		temp_node->index = index;
		if (temp_node->nbr < smallest_node->nbr)
		{
			smallest_node = temp_node;
			smallest_node->index = index;
		}
		temp_node = temp_node->next;
		index++;
	}
	return (smallest_node);
}

/**
 * @brief Finds the smallest number closest to a given node in a stack.
 *
 * This function iterates through the stack and finds the node with the smallest
 * value that is smaller than the given node. It returns the node with the
 * smallest value that is smaller than the given node.
 *
 * @param node Pointer to the node to compare.
 * @param stack Pointer to the stack to search.
 * @return Pointer to the node with the smallest value that is smaller than the
 * given node.
 */
t_node	*find_the_smallest_closest_number(t_node *node, t_stack *stack)
{
	t_node	*closest_smaller_node;
	t_node	*temp_node;
	int		index;

	index = 0;
	temp_node = stack->top;
	closest_smaller_node = NULL;
	while (index < stack->size)
	{
		temp_node->index = index;
		if (temp_node->nbr < node->nbr)
		{
			if (closest_smaller_node == NULL
				|| temp_node->nbr > closest_smaller_node->nbr)
			{
				closest_smaller_node = temp_node;
				closest_smaller_node->index = index;
			}
		}
		temp_node = temp_node->next;
		index++;
	}
	return (closest_smaller_node);
}

/**
 * @brief Finds the biggest number closest to a given node in a stack.
 *
 * This function iterates through the stack and finds the node with the largest
 * value that is larger than the given node. It returns the node with the largest
 * value that is larger than the given node.
 *
 * @param node Pointer to the node to compare.
 * @param stack Pointer to the stack to search.
 * @return Pointer to the node with the largest value that is larger than the
 * given node.
 */
t_node	*find_the_biggest_closest_number(t_node *node, t_stack *stack)
{
	t_node	*closest_bigger_node;
	t_node	*temp_node;
	int		index;

	index = 0;
	temp_node = stack->top;
	closest_bigger_node = NULL;
	while (index < stack->size)
	{
		temp_node->index = index;
		if (temp_node->nbr > node->nbr)
		{
			if (closest_bigger_node == NULL
				|| temp_node->nbr < closest_bigger_node->nbr)
			{
				closest_bigger_node = temp_node;
				closest_bigger_node->index = index;
			}
		}
		temp_node = temp_node->next;
		index++;
	}
	return (closest_bigger_node);
}

/**
 * @brief Finds the node to push in stack b.
 *
 * This function iterates through the stack a 
	* and finds the node with the smallest cost to push to stack b. 
	* It returns the node with the smallest cost to push to stack b.
 *
 * @param stacks Pointer to the stacks to search.
 * @return Pointer to the node with the smallest cost to push to stack b.
 */
t_node	*find_node_to_push_in_stack_b(t_stacks *stacks)
{
	int		index;
	int		node_cost;
	int		cheapest_cost;
	t_node	*node;
	t_node	*cheapest_node;

	index = 0;
	cheapest_cost = 0;
	node = stacks->a.top;
	cheapest_node = NULL;
	while (index < stacks->a.size)
	{
		node->index = index;
		node_cost = calculate_cost_to_push_node_to_stack_b(node, stacks);
		if (cheapest_node == NULL || node_cost < cheapest_cost)
		{
			cheapest_node = node;
			cheapest_cost = node_cost;
			cheapest_node->index = index;
		}
		node = node->next;
		index++;
	}
	return (cheapest_node);
}
