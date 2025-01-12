/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/04 17:29:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include	<stdbool.h>
typedef struct s_num_str
{
	int			size;
	const char	*value;
	bool		has_signal;
	bool		is_negative;
}	t_num_str;
typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

typedef struct s_env
{
	t_stack	sa;
	t_stack	sb;
}	t_env;
#endif
