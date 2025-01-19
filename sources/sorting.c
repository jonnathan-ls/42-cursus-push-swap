/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/24 00:36:16 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// validates if the stack is sorted in ascending order
// if not sorted then verif if stack has 2 elements, if yes swap them

// if stack has 3 elements, sort them in ascending order

// if stack has more than 3 elements, then sort the stack with the following algorithm: Turk Algorithm

// push until 2 elements to stack b, mantaining the stack a with 3 elements
// while the stack a has more than 3 elements
// find the cheapest node to push to b, sorting b stack in descending order

// a target_node node in b is the closest smaller number to the a node
// if no closest smaller number is found, then the target_node node is the max value in b

// cost analysis:
// find the cheapest node to push to b
// the formula is: cost = x operations to bring a node to the top of a + y operations to bring a->target_node to the top of b
// the cheapest node to push to b is the one with the lowest cost


// when the stack a for equal or less than 3 elements
// then sort the stack a in ascending order

// push back to stack a the elements in stack b in descending order

// every b node has a target_node node in a that is the closest bigger number to the b node
// if no closest bigger number is found, then the target_node node is the min value in a
// calculate the cost of pushing a node from b to a
// the formula is: cost = only x operations to bring a node to the top

// afeter pushing all the nodes from b to a, sort the stack a in ascending order
// moving the smallest number to the top of the stack

static t_node	*find_the_smallest_closest_number(t_node *node, t_stack *stack)
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

static t_node	*find_the_biggest_closest_number(t_node *node, t_stack *stack)
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


// static void	move_two_elements_to_stack_b(t_env *env)
// {
// 	pb(env);
// 	pb(env);
// 	if (env->b.top->nbr > env->b.top->next->nbr)
// 		sb(env);
// }

void	set_target_nodes_in_a(t_env *env)
{
	int		index;
	t_node	*node;
	t_node	*target_node;

	index = 0;
	node = env->a.top;
	while (index < env->a.size)
	{
		node->index = index;
		target_node = find_the_smallest_closest_number(node, &env->b);
		if (target_node == NULL)
			target_node = find_the_biggest_number(&env->b);
		node->target_node = target_node;
		node = node->next;
		index++;
	}
}

// static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
// {
// 	int	len_a; //To store the length of stack `a`
// 	int	len_b; //To store the length of stack `b`

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (a) //Loop through each node until the end of the stack is reached
// 	{
// 		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
// 		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
// 			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
// 		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
// 			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
// 		else //If `a` node is indeed above median and its target `b` node is below median
// 			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
// 		a = a->next; //Move to the next `a` node for its cost analysis
// 	}
// }


int	calculate_cost_to_push_node_to_stack_b(t_node *node, t_env *env)
{
	int	cost_to_push;

	cost_to_push = node->index;
	if (!node->above_middle_stack)
		cost_to_push = env->a.size - node->index;
	if (node->target_node->above_middle_stack)
		cost_to_push += node->target_node->index;
	else
		cost_to_push += env->b.size - node->target_node->index;
	return (cost_to_push);
}

t_node	*find_node_to_push_in_stack_b(t_env *env)
{
	int		index;
	int		node_cost;
	t_node	*node;
	t_node	*cheapest_node;
	int		cheapest_cost;

	index = 0;
	cheapest_cost = 0;
	node = env->a.top;
	cheapest_node = NULL;
	while (index < env->a.size)
	{
		node->index	= index;
		node_cost = calculate_cost_to_push_node_to_stack_b(node, env);
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

// static void	push_node_in_stack_b(t_env *env, t_node *node)
// {
// 	if (node->target_node->index <= env->b.size / 2)
// 		while (env->b.top != node->target_node)
// 			rb(env);
// 	else
// 		while (env->b.top != node->target_node)
// 			rrb(env);
// 	if (node == env->a.top)
// 		return (pb(env));
// 	if (node == env->a.top->next)
// 		sa(env);
// 	else if (node->index <= env->a.size / 2)
// 		while (env->a.top != node)
// 			ra(env);
// 	else
// 		while (env->a.top != node)
// 			rra(env);
// 	pb(env);
// } // TODO da para melhorar para usar rr e rrr ?

static void push_node_in_stack_b(t_env *env, t_node *node) {
	int a_moves = (node->index <= env->a.size / 2) ? node->index : env->a.size - node->index;
	int b_moves = (node->target_node->index <= env->b.size / 2) ? node->target_node->index : env->b.size - node->target_node->index;

	while (a_moves > 0 && b_moves > 0)
	{
		if (node->index <= env->a.size / 2 && node->target_node->index <= env->b.size / 2)
			rr(env);
		else if (node->index > env->a.size / 2 && node->target_node->index > env->b.size / 2)
			rrr(env);
		else
			break ;
		a_moves--;
		b_moves--;
	}

	while (a_moves-- > 0)
	{
		if (node->index <= env->a.size / 2)
			ra(env);
		else
			rra(env);
	}

	while (b_moves-- > 0)
	{
		if (node->target_node->index <= env->b.size / 2)
			rb(env);
		else
			rrb(env);
	}

	pb(env);
}

static void push_node_in_stack_a(t_env *env, t_node *node) {
    int a_moves = (node->index <= env->a.size / 2) ? node->index : env->a.size - node->index;

    while (a_moves-- > 0) {
        if (node->index <= env->a.size / 2) ra(env);
        else rra(env);
    }

    pa(env);
}
void	sort_stack(t_env *env)
{
	t_node *node;
	t_node *smallest_value;
	int 	size;
	// move_two_elements_to_stack_b(env);

	// Necessario ?
	size = env->a.size;
	if (size-- > 3 && !is_sorted(&env->a))
		pb(env);
	if (size-- > 3 && !is_sorted(&env->a))
		pb(env);
	
	while (size-- > 3 && !is_sorted(&env->a))
	{
		update_index_in_stack(&env->a);
		update_index_in_stack(&env->b);
		set_target_nodes_in_a(env);
		node = find_node_to_push_in_stack_b(env);
		push_node_in_stack_b(env, node);
	}
	sort_three(env);
	while (env->b.size > 0)
	{
		update_index_in_stack(&env->a);
		update_index_in_stack(&env->b);
		node = find_the_biggest_closest_number(env->b.top, &env->a);
		if (node == NULL)
			node = find_the_smallest_number(&env->a);
		push_node_in_stack_a(env, node);
	}
	update_index_in_stack(&env->a);
	smallest_value = find_the_smallest_number(&env->a);
	if (smallest_value->index <= env->a.size / 2)
		while (env->a.top != smallest_value)
			ra(env);
	else
		while (env->a.top != smallest_value)
			rra(env);
}
