/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:45:31 by                   #+#    #+#             */
/*   Updated: 2025/02/04 20:01:47 by jlacerda         ###   ########.fr       */
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
int	execute_instruction(char *instruction, t_stacks *stacks)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		return (sa(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		return (sb(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		return (ss(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		return (pa(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		return (pb(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		return (ra(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		return (rb(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		return (rr(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		return (rra(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		return (rrb(stacks, PRINT_OP), 1);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		return (rrr(stacks, PRINT_OP), 1);
	return (0);
}

/**
	* @brief Processes the instructions.
	*
	* This function reads instructions from stdin, 
	* executes them on the stacks, and checks if the stacks are sorted.
	*
	* @param stacks The stacks.
 */
static void	process_instructions(t_stacks *stacks)
{
	char	*line;
	int		is_valid_operation;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		is_valid_operation = execute_instruction(line, stacks);
		if (!is_valid_operation)
			break ;
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (line != NULL && !is_valid_operation)
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	else
	{
		if (is_sorted(&stacks->a) && stacks->b.size == 0)
			ft_putstr_fd("OK\n", STDOUT_FILENO);
		else
			ft_putstr_fd("KO\n", STDOUT_FILENO);
	}
	free(line);
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
void	initialize_stacks_with_args_bonus(
	t_stacks *stacks, int argc, char **args, int args_count)
{
	if (!init_stacks(stacks, args_count, args))
	{
		free_mallocs(stacks, argc, args, args_count);
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Main function for the checker program.
 *
	* This function reads the arguments, validates them, initializes the stacks,
	* processes the instructions, and frees the mallocs.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return EXIT_SUCCESS if the stacks are sorted, EXIT_FAILURE otherwise.
 */
int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	stacks;
	int			args_count;

	if (argc == 1)
		return (EXIT_SUCCESS);
	args = get_arguments(argc, argv);
	args_count = ft_strslen(args);
	validates_arguments(args, args_count, argc);
	initialize_stacks_with_args_bonus(&stacks, argc, args, args_count);
	process_instructions(&stacks);
	free_mallocs(&stacks, argc, args, args_count);
	return (EXIT_SUCCESS);
}
