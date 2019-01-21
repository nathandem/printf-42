/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:50:54 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/21 16:45:19 by nde-maes         ###   ########.fr       */
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
	t_dir			*cur_dir;

	cur_dir = parse_dir(str);

}
