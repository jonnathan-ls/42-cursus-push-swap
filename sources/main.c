/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 20:22:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

static void	validates_arguments(char **args, int args_count, int argc)
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

static void	process_stack(
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

static void	sort_stack(t_stacks *stacks)
{
	if (stacks->a.size == 2)
		sa(stacks);
	else if (stacks->a.size == 3)
		sort_three(stacks);
	else
		sort_big(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**args;
	int			args_count;

	args = get_arguments(argc, argv);
	args_count = ft_strslen(args);
	validates_arguments(args, args_count, argc);
	process_stack(&stacks, argc, args, args_count);
	sort_stack(&stacks);
	free_mallocs(&stacks, argc, args, args_count);
	return (EXIT_SUCCESS);
}
