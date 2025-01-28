/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:25:59 by jlacerda          #+#    #+#             */
/*   Updated: 2025/01/27 23:09:33 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "macros.h"
# include "structs.h"
# include "push_swap.h"

# ifndef PRINT_OP
/**
 * @brief Macro to control operation printing.
 *
 * This macro defines whether operations 
	* should be printed to stdout (1) or not (0).
 * Used throughout the program to control output verbosity.
 *
 * @def PRINT_OP
 * @param 0 Disable operation printing
 * @param 1 Enable operation printing
 */
#  define PRINT_OP 0
# endif

#endif
