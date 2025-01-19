/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/23 22:56:13 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdbool.h>
# include "libft.h"

typedef struct s_num_str
{
	int			size;
	const char	*value;
	bool		has_signal;
	bool		is_negative;
}	t_num_str;

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
	bool			above_middle_stack;
	int push_cost;
	bool cheapest;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*base;
}	t_stack;

typedef struct s_env
{
	t_stack	a;
	t_stack	b;
}	t_env;

typedef struct s_cost
{
	int		cost_to_push;
	bool	above_middle_stack;
}	t_cost;

typedef struct s_cost_push
{
	t_cost	a;
	t_cost	b;
}	t_cost_push;
#endif
