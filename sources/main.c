/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 22:58:07 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * @brief Sorts the stack.
 *
 * This function sorts the stack.
 *
 * @param stacks The stacks.
 */
static void	sort_stack(t_stacks *stacks)
{
	if (stacks->a.size == 2)
		sa(stacks, PRINT_OPT);
	else if (stacks->a.size == 3)
		sort_three(stacks);
	else
		sort_big(stacks);
}

/**
 * @brief Main function.
 *
 * This function is the main function.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return The exit status.
 */
int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	stacks;
	int			args_count;

	args = get_arguments(argc, argv);
	args_count = ft_strslen(args);
	validates_arguments(args, args_count, argc);
	initialize_stacks_with_args(&stacks, argc, args, args_count);
	sort_stack(&stacks);
	free_mallocs(&stacks, argc, args, args_count);
	return (EXIT_SUCCESS);
}
