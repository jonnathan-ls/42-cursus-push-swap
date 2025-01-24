/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/24 02:00:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static bool	is_greater_than_integer(t_num_str num)
{
	int		index;
	char	*str_to_compare;

	index = 0;
	if (num.has_signal)
		index++;
	if (num.is_negative)
		str_to_compare = INT_MIN_STR;
	else
		str_to_compare = INT_MAX_STR;
	while (num.value[index])
	{
		if (num.value[index] < str_to_compare[index])
			return (false);
		if (num.value[index] > str_to_compare[index])
			return (true);
		index++;
	}
	return (true);
}

static bool	is_valid_integer(const char *number_str)
{
	int			index;
	t_num_str	num_str;

	index = 0;
	num_str.value = number_str;
	num_str.size = ft_strlen(number_str);
	num_str.is_negative = number_str[index] == '-';
	num_str.has_signal = (num_str.is_negative || (number_str[index] == '+'));
	if (num_str.has_signal)
		index++;
	while (number_str[index])
	{
		if (!ft_isdigit(number_str[index]))
			return (false);
		index++;
	}
	if (num_str.is_negative)
		index--;
	if (index > INT_SIZE_DIGITS)
		print_error_and_exit_failure();
	if (index == INT_SIZE_DIGITS && is_greater_than_integer(num_str))
		print_error_and_exit_failure();
	return (true);
}

static void	validates_arguments(char **args, int size)
{
	int	curr;
	int	next;

	if (args == NULL)
		print_error_and_exit_failure();
	curr = 0;
	while (curr < size)
	{
		if (!is_valid_integer(args[curr]))
			print_error_and_exit_failure();
		curr++;
	}
	curr = 0;
	while (curr < size)
	{
		next = curr + 1;
		while (next < size)
		{
			if (ft_atoi(args[curr]) == ft_atoi(args[next]))
				print_error_and_exit_failure();
			next++;
		}
		curr++;
	}
}

void	push_node(t_stack *stack, t_node *node)
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

t_node	*new_node(int number)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_error_and_exit_failure();
	node->nbr = number;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_stacks(t_env *env,	int size, char **args_list)
{
	int		number;
	t_node	*node;
	t_node	*previous_node;

	previous_node = NULL;
	env->a.top = NULL;
	env->b.top = NULL;
	env->a.base = NULL;
	env->b.base = NULL;
	env->a.size = 0;
	env->b.size = 0;
	while (size > 0)
	{
		number = ft_atoi(args_list[size - 1]);
		node = new_node(number);
		node->index = size - 1;
		if (previous_node != NULL)
			node->prev = previous_node;
		push_node(&env->a, node);
		previous_node = node;
		env->a.size++;
		size--;
	}
	env->a.base->next = env->a.top;
	env->a.top->prev = env->a.base;
}

void sort_three(t_env *env)
{
	t_node	*biggest_node;

	biggest_node = find_the_biggest_number(&env->a);
	if (biggest_node == env->a.top)
		ra(env);
	else if (biggest_node == env->a.top->next)
		rra(env);
	if (env->a.top->nbr > env->a.top->next->nbr)
		sa(env);
}

void free_mallocs(t_env *env, int argc, char **args, int args_count)
{
	int		index;

	index = 0;
	while (index < env->a.size)
	{
		free(env->a.top);
		env->a.top = env->a.top->next;
		index++;
	}
	if (argc == 2)
	{
		index = 0;
		while (index < args_count)
		{
			free(args[index]);
			index++;
		}
		free(args);
	}
}

int	main(int argc, char **argv)
{
	t_env	env;
	char	**args;
	int		args_count;

	args = NULL;
	if (argc == 1)
		return (EXIT_FAILURE);
	if (argc == 2 && argv[1][0] != '\0')
		args = ft_split(argv[1], SPACE_CHAR);
	else
		args = argv + 1;
	args_count = ft_strslen(args);
	validates_arguments(args, args_count);
	init_stacks(&env, args_count, args);
	if (is_sorted(&env.a))
		return (EXIT_SUCCESS);
	if (env.a.size == 2)
		sa(&env);
	else if (env.a.size == 3)
		sort_three(&env);
	else
		sort_stack(&env);
	free_mallocs(&env, argc, args, args_count);
	return (EXIT_SUCCESS);
}
