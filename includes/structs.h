/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/27 23:14:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "libft.h"
# include <stdbool.h>

/**
 * @brief Represents a number string.
 *
 * @param size The size of the number string.
 * @param value The value of the number string.
 * @param has_signal Whether the number string has a signal.
 * @param is_negative Whether the number string is negative.
 */
typedef struct s_num_str
{
	int			size;
	const char	*value;
	bool		has_signal;
	bool		is_negative;
}	t_num_str;

/**
 * @brief Represents a node in a stack.
 *
 * @param nbr The value of the node.
 * @param index The index of the node.
 * @param above_middle Whether the node is above the middle of the stack.
 */
typedef struct s_node
{
	int				nbr;
	int				index;
	bool			above_middle;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}	t_node;

/**
 * @brief Represents a stack.
 *
 * @param size The size of the stack.
 * @param top The top of the stack.
 * @param base The base of the stack.
 */
typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*base;
}	t_stack;

/**
 * @brief Represents a pair of stacks.
 *
 * @param a The first stack.
 * @param b The second stack.
 */
typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

#endif
