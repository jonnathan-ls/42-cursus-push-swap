/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/25 19:40:13 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "macros.h"
# include "structs.h"
# include <stdbool.h>
# include <stdio.h>

void	print_error_and_exit_failure(void);

// Operations
void	rra(t_env *env);
void	rrb(t_env	*env);
void	rrr(t_env *env);
void	ra(t_env	*env);
void	rb(t_env	*env);
void	rr(t_env *env);
void	pa(t_env *env);
void	pb(t_env *env);
void	sa(t_env	*env);
void	sb(t_env	*env);
void	ss(t_env	*env);

// Utils
bool	is_sorted(t_stack *stack);
void	update_index_in_stack(t_stack *stack);
void	set_target_node_for_each_element_in_stack_a(t_env *env);
void	free_mallocs(t_env *env, int argc, char **args, int args_len);
int		calculate_cost_to_push_node_to_stack_b(t_node *node, t_env *env);

// Stack
void	free_mallocs(t_env *env, int argc, char **args, int args_len);
bool	init_stacks(t_env *env,	int size, char **args);

// Validations
bool	is_greater_than_integer(t_num_str num);
bool	is_valid_integer(const char *number_str);
bool	arguments_are_valid(char **args, int size);

// Finder
t_node	*find_the_biggest_number(t_stack *stack);
t_node	*find_the_smallest_number(t_stack *stack);
t_node	*find_node_to_push_in_stack_b(t_env *env);
t_node	*find_the_biggest_closest_number(t_node *node, t_stack *stack);
t_node	*find_the_smallest_closest_number(t_node *node, t_stack *stack);

// Pusher
void	push_node_in_stack_b(t_env *env, t_node *node);
void	push_node_in_stack_a(t_env *env, t_node *node);

// Sorter
void	sort_three(t_env *env);
void	sort_big(t_env *env);

#endif
