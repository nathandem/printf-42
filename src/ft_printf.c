/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:50:54 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/20 18:40:03 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is the entry point of the function.
*/

#include "ft_printf.h"

void			ft_printf(const char *str, ...)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
			i += handle_directive(str + i); // with last char of the directive?
		else
			ft_putchar(str[i]);
	}
}

int				handle_directive(const char *str_dir)
{
	t_dir			cur_dir;

	cur_dir = parse_dir(str);

	// here call function(s) which will use the info of cur_dir

	// 1) Try to see if generic functions could handle the flags.
	// 2) If not possible, try doing it function by function.
	// 3) If some grouping possible, like all digits behave the same,
	// create functions so that certain flags are handled the same for say
	// digits.
	// When this reflexion on generic vs specific flag handler is done,
	// create the functions and the global array of structures doing the mapping

}
