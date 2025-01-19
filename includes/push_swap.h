/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/22 21:56:12 by jlacerda         ###   ########.fr       */
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

bool	is_sorted(t_stack *stack);
t_node	*find_the_biggest_number(t_stack *stack);
t_node	*find_the_smallest_number(t_stack *stack);
void	update_index_in_stack(t_stack *stack);
void sort_three(t_env *env);
void	sort_stack(t_env *env);

#endif
