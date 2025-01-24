/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/24 01:28:07 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_error_and_exit_failure(void)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

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
