/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 16:46:54 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_greater_than_integer(t_num_str num)
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
	return (false);
}

bool	is_valid_integer(const char *number_str)
{
	int			index;
	t_num_str	num_str;

	index = 0;
	num_str.value = number_str;
	num_str.size = ft_strlen(number_str);
	num_str.is_negative = number_str[index] == '-';
	num_str.has_signal = (num_str.is_negative || (number_str[index] == '+'));
	if (num_str.size == 0 || (num_str.has_signal && num_str.size == 1))
		return (false);
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
		return (false);
	if (index == INT_SIZE_DIGITS && is_greater_than_integer(num_str))
		return (false);
	return (true);
}

bool	arguments_are_valid(char **args, int size)
{
	int	curr;
	int	next;

	if (args == NULL)
		return (false);
	curr = 0;
	while (curr < size)
	{
		if (!is_valid_integer(args[curr]))
			return (false);
		curr++;
	}
	curr = 0;
	while (curr < size)
	{
		next = curr + 1;
		while (next < size)
		{
			if (ft_atoi(args[curr]) == ft_atoi(args[next]))
				return (false);
			next++;
		}
		curr++;
	}
	return (true);
}
