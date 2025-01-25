/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 20:21:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_properties(t_stacks *stacks)
{
	stacks->a.base = NULL;
	stacks->b.base = NULL;
	stacks->a.top = NULL;
	stacks->b.top = NULL;
	stacks->a.size = 0;
	stacks->b.size = 0;
}

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
