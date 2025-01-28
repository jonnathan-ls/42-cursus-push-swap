/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 22:57:50 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Gets the arguments from the command line.
 *
 * This function gets the arguments from the command line and validates them.
 * It returns the arguments.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return The arguments.
 */
char	**get_arguments(int argc, char **argv)
{
	char	**args;
	int		string_with_multiple_args;

	if (argc == 1)
		return (EXIT_SUCCESS);
	string_with_multiple_args = argc == 2;
	if (string_with_multiple_args && argv[1][0] == NULL_CHAR)
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (string_with_multiple_args)
		args = ft_split(argv[1], SPACE_CHAR);
	else
		args = argv + 1;
	if (string_with_multiple_args && args[0] == NULL)
	{
		free(args);
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (args);
}

/**
 * @brief Validates the arguments.
 *
 * This function validates the arguments.
 *
 * @param args The arguments.
 * @param args_count The number of arguments.
 * @param argc The number of arguments.
 */
void	validates_arguments(char **args, int args_count, int argc)
{
	int	index;

	if (!arguments_are_valid(args, args_count))
	{
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
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Initializes the stacks with the arguments.
 *
 * This function initializes the stacks with the arguments.
 *
 * @param stacks The stacks.
 * @param argc The number of arguments.
 * @param args The arguments.
 * @param args_count The number of arguments.
 */
void	initialize_stacks_with_args(
	t_stacks *stacks, int argc, char **args, int args_count)
{
	if (!init_stacks(stacks, args_count, args))
	{
		free_mallocs(stacks, argc, args, args_count);
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (is_sorted(&stacks->a))
	{
		free_mallocs(stacks, argc, args, args_count);
		exit(EXIT_SUCCESS);
	}
}
