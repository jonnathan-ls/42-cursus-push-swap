/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/25 19:46:28 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	**get_arguments(int argc, char **argv)
{
	char	**args;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (argv[1][0] == '\0')
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (argc == 2 && argv[1][0] != '\0')
		args = ft_split(argv[1], SPACE_CHAR);
	else
		args = argv + 1;
	if (argc == 2 && args[0] == NULL)
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

static void	process_stack(t_env *env, int argc, char **args, int args_count)
{
	if (!init_stacks(env, args_count, args))
	{
		free_mallocs(env, argc, args, args_count);
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (is_sorted(&env->a))
	{
		free_mallocs(env, argc, args, args_count);
		exit(EXIT_SUCCESS);
	}
}

static void	sort_stack(t_env *env)
{
	if (env->a.size == 2)
		sa(env);
	else if (env->a.size == 3)
		sort_three(env);
	else
		sort_big(env);
}

int	main(int argc, char **argv)
{
	t_env	env;
	char	**args;
	int		args_count;

	args = NULL;
	args = get_arguments(argc, argv);
	args_count = ft_strslen(args);
	validates_arguments(args, args_count, argc);
	process_stack(&env, argc, args, args_count);
	sort_stack(&env);
	free_mallocs(&env, argc, args, args_count);
	return (EXIT_SUCCESS);
}
