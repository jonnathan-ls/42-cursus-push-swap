/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/21 22:13:05 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// static bool	is_desc_sorted(t_stack *stack)
// {
// 	t_node	*node;

// 	node = stack->top;
// 	while (node && node->next)
// 	{
// 		if (node->nbr < node->next->nbr)
// 			return (false);
// 		node = node->next;
// 	}
// 	return (true);
// }

static t_node *find_min_node(t_env *env)
{
	t_node	*min_node;
	t_node	*node;
	int		pos;

	min_node = NULL;
	node = env->a.base;
	pos = 0;
	while (pos < env->a.size)
	{
		if (min_node == NULL)
			min_node = node;
		if (node->nbr > min_node->nbr)
		{
			min_node = node;
			min_node->index = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_node);
}

// E obtem o numero de maior valor da pilha de A que seja o maior mais proximo do topo de B
static t_node	*find_max_node(t_env *env)
{
	t_node	*max_node;
	t_node	*prev_max_node;
	t_node	*node;
	int		pos;

	max_node = NULL;
	node = env->a.top;
	pos = 0;
	while (pos < env->a.size)
	{
		if (max_node == NULL)
			max_node = node;
		if (node->nbr > max_node->nbr)
		{
			prev_max_node = max_node;
			max_node = node;
			max_node->index = pos;
		}
		if (node->nbr > prev_max_node->nbr && node->nbr < max_node->nbr)
		{
			prev_max_node = max_node;
			max_node = node;
			max_node->index = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_node);
}

static void	move_max_to_top(t_env *env, t_node *max_node)
{
	// 	[X] Verifica se o numero encontrado esta no topo, na segunda posicao ou esta antes ou depois do meio da pilha
// 		Se estiver no	topo de A, faz push em B
// 		Se estiver na segunda posicao, faz swap	e push em B
// 		Se estiver antes ou for o meio, faz ra ate ser o topo e push em B
// 		Se estiver depois do meio, faz rra ate ser o topo e push em B
	if (max_node == env->a.top)
		pb(env);
	else if (max_node == env->a.top->next)
	{
		sa(env);
		pb(env);
	}
	else if (max_node->index <= env->a.size / 2)
	{
		while (env->a.top != max_node)
			ra(env);
		pb(env);
	}
	else
	{
		while (env->a.top != max_node)
			rra(env);
		pb(env);
	}
}

static void	move_two_to_b(t_env *env)
{
	pb(env);
	pb(env);
	if (env->b.top->nbr > env->b.top->next->nbr)
		sb(env);
}

void	sort_stack(t_env *env)
{
	t_node	*max_node;
	t_node	*temp_node;
	bool			stack_b_is_ordered;

	stack_b_is_ordered = false;
	max_node = find_max_node(env);
	move_two_to_b(env);
	while (env->a.size > 0)
	{
		temp_node = find_max_node(env);
		if (temp_node->nbr > env->b.top->nbr)
			move_max_to_top(env, temp_node);
		else
		{
			if (stack_b_is_ordered == false)
			{
				rrb(env);
				stack_b_is_ordered = true;
			}
			temp_node	= find_max_node(env);
			if (temp_node->nbr > env->b.top->nbr)
			{
				move_max_to_top(env, temp_node);
				continue ;
			}
			else
				break ;
		}
	}
	while (env->b.top->next != max_node)
		rb(env);
	while (env->a.size > 0)
	{
		temp_node = find_min_node(env);
		if (temp_node != NULL && temp_node->nbr < env->b.base->nbr)
			move_max_to_top(env, temp_node);
		rb(env);
	}
	while (env->b.size > 0)
		pa(env);
}
