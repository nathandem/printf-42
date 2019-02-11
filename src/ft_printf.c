/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:50:54 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/11 19:53:06 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is the entry point of the function.
*/

#include "ft_printf.h"
#include "ft_d2h.h"


#include <stdio.h>

void			handle_dir(const char *dir, va_list *ap, int *pos, int *ret)
{
	t_dir			*cur_dir;
	char			*str;
	int				i;

	cur_dir = parse_dir(dir);
	if (cur_dir->type == '.')
	{
		*pos += cur_dir->len;
		free(cur_dir);
		return ;
	}

	i = -1;
	while (++i < 13)  // to be changed at each new insert
	{
		if ((g_d2h[i].type == cur_dir->type)
		&& (g_d2h[i].size == cur_dir->size))
			str = g_d2h[i].ft_d2h(ap, cur_dir);
	}

	ft_putstr(str);

	*pos += (cur_dir->len - 1);
	*ret += (int)ft_strlen(str);
	free(cur_dir);
	free(str);
	return ;
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	int				ret;  // nb of chars printed to the screen

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')  // handle special case of %%
			handle_dir(format + i, &ap, &i, &ret);
		else
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (ret);
}
