/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/25 20:21:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "macros.h"
# include "structs.h"

// Operations
void	ra(t_stacks	*stacks);
void	rb(t_stacks	*stacks);
void	rr(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	sa(t_stacks	*stacks);
void	sb(t_stacks	*stacks);
void	ss(t_stacks	*stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks	*stacks);
void	rrr(t_stacks *stacks);

// Utils
bool	is_sorted(t_stack *stack);
void	update_index_in_stack(t_stack *stack);
void	set_target_node_for_each_element_in_stack_a(t_stacks *stacks);
void	free_mallocs(t_stacks *stacks, int argc, char **args, int args_len);
int		calculate_cost_to_push_node_to_stack_b(t_node *node, t_stacks *stacks);

// Stack
bool	init_stacks(t_stacks *stacks,	int size, char **args);
void	free_mallocs(t_stacks *stacks, int argc, char **args, int args_len);

// Validations
bool	is_greater_than_integer(t_num_str num);
bool	is_valid_integer(const char *number_str);
bool	arguments_are_valid(char **args, int size);

// Finder
t_node	*find_the_biggest_number(t_stack *stack);
t_node	*find_the_smallest_number(t_stack *stack);
t_node	*find_node_to_push_in_stack_b(t_stacks *stacks);
t_node	*find_the_biggest_closest_number(t_node *node, t_stack *stack);
t_node	*find_the_smallest_closest_number(t_node *node, t_stack *stack);

// Pusher
void	push_node_in_stack_b(t_stacks *stacks, t_node *node);
void	push_node_in_stack_a(t_stacks *stacks, t_node *node);

// Sorter
void	sort_big(t_stacks *stacks);
void	sort_three(t_stacks *stacks);

#endif
