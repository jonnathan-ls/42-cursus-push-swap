/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/01/27 23:06:47 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "checker_bonus.h"

/**
 * @brief Executes an instruction on the stacks.
 *
 * This function executes an instruction on the stacks.
 *
 * @param instruction The instruction to execute.
 * @param stacks The stacks.
 */
static void	execute_instruction(char *instruction, t_stacks *stacks)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(stacks, PRINT_OP);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(stacks, PRINT_OP);
}

/**
 * @brief Main function for the checker program.
 *
 * This function reads instructions from stdin, executes them on the stacks,
 * and checks if the stacks are sorted.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return EXIT_SUCCESS if the stacks are sorted, EXIT_FAILURE otherwise.
 */
int	main(int argc, char **argv)
{
	char		*line;
	char		**args;
	t_stacks	stacks;
	int			args_count;

	args = get_arguments(argc, argv);
	args_count = ft_strslen(args);
	validates_arguments(args, args_count, argc);
	initialize_stacks_with_args(&stacks, argc, args, args_count);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		execute_instruction(line, &stacks);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (is_sorted(&stacks.a) && stacks.b.size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_mallocs(&stacks, argc, args, args_count);
	return (EXIT_SUCCESS);
}
