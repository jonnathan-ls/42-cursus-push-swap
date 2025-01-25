/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 17:20:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_properties(t_env *env)
{
	env->a.base = NULL;
	env->b.base = NULL;
	env->a.top = NULL;
	env->b.top = NULL;
	env->a.size = 0;
	env->b.size = 0;
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

bool	init_stacks(t_env *env,	int size, char **args)
{
	int		number;
	t_node	*node;
	t_node	*previous_node;

	previous_node = NULL;
	init_properties(env);
	while (size > 0)
	{
		number = ft_atoi(args[size - 1]);
		node = new_node(number);
		if (!node)
			return (false);
		node->index = size - 1;
		if (previous_node != NULL)
			node->prev = previous_node;
		push_node_to_stack(&env->a, node);
		previous_node = node;
		env->a.size++;
		size--;
	}
	env->a.base->next = env->a.top;
	env->a.top->prev = env->a.base;
	return (true);
}
