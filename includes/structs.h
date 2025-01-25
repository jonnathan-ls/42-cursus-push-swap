/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/25 20:20:02 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "libft.h"
# include <stdbool.h>

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
	bool			above_middle;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
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

#endif
