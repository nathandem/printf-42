/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:42:15 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/22 10:50:00 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			handle_char(t_dir *cur_dir)
{
	// what applies:
	// -, width
	
	
	
	// order of processing
}


void			handle_digit(t_dir *cur_dir)
{
	// What applies:
	// 0, -, ` ` or +, width, precision, size, operation
	// Order of processing:
	// size
	// precision
	// operation
	// ` ` or +, or none of them
	// width
	// 0 or -, or none of them
	// Note: try not to hold an intermediate state in memory, directly output
	//       the resulting string.
	
	// do the operation/conversion first (itoa), then see
	

}
