/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/12 15:46:07 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

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

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (EXIT_FAILURE);
	if (argc < 3)
		print_error_and_exit_failure();
	validates_arguments(argc, argv);
	ft_printf("Arguments are valid\n");
	return (EXIT_SUCCESS);
}
