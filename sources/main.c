/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/18 18:02:37 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static bool	is_greater_than_integer(t_num_str num)
{
	int	index;

	index = 0;
	if (num.has_signal)
		index++;
	if (num.is_negative)
	{
		while (num.value[index])
		{
			if (num.value[index] > INT_MIN_STR[index])
				return (true);
			index++;
		}
	}
	else
	{
		while (num.value[index])
		{
			if (num.value[index] > INT_MAX_STR[index])
				return (true);
			index++;
		}
	}
	return (false);
}

static bool	is_valid_integer(const char *number_str)
{
	int			index;
	t_num_str	num_str;

	index = 0;
	num_str.value = number_str;
	num_str.size = ft_strlen(number_str);
	num_str.is_negative = number_str[index] == '-';
	num_str.has_signal = num_str.is_negative || number_str[index] == '+';
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

static void	validates_arguments(int argc, char **argv)
{
	int	curr;
	int	next;

	curr = 1;
	while (curr < argc)
	{
		if (!is_valid_integer(argv[curr]))
			print_error_and_exit_failure();
		curr++;
	}
	curr = 1;
	while (curr < argc)
	{
		next = curr + 1;
		while (next < argc)
		{
			if (ft_atoi(argv[curr]) == ft_atoi(argv[next]))
				print_error_and_exit_failure();
			next++;
		}
		curr++;
	}
}

void	init_stacks(t_env *env,	int argc, char **argv)
{
	int		index;
	int		*number;
	t_list	*new;

	index = 0;
	env->a.head = NULL;
	env->a.size = 0;
	env->b.head = NULL;
	env->b.size = 0;
	while (index < argc)
	{
		number = (int *)malloc(sizeof(int));
		if (!number)
			print_error_and_exit_failure();
		*number = ft_atoi(argv[index]);
		new = ft_lstnew(number);
		if (!new)
			print_error_and_exit_failure();
		ft_lstadd_back(&env->a.head, new);
		env->a.size++;
		index++;
	}
}

bool	is_string_with_arguments(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == SPACE_CHAR || str[index] == TAB_CHAR)
			return (true);
		index++;
	}
	return (false);
}
int	main(int argc, char **argv)
{
	t_env	env;
	t_list	*temp;
	char	**string_list;
	int		size;

	if (argc == 1)
		return (EXIT_FAILURE);
	if (argc == 2 && is_string_with_arguments(argv[1]))
	{
		string_list = ft_split(argv[1], SPACE_CHAR);
		if (!string_list)
			print_error_and_exit_failure();
		size = ft_strslen(string_list);
		validates_arguments(size, string_list);
		init_stacks(&env, size, string_list);
	}
	else
	{
		validates_arguments(argc, argv);
		init_stacks(&env, argc, argv + 1);
	}
	temp = env.a.head;
	while (temp)
	{
		ft_printf("%d\n", *(int *)temp->content);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
