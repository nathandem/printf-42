/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:50:54 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/12 13:34:49 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_d2h.h"

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
	while (++i < 33)  // to be changed at each new insert
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

/*
** Just a trick on the Norm to have ft_printf fit in 25 lines max.
*/

void			putchar_and_increment_ret(char c, int *ret)
{
	ft_putchar(c);
	ret++;
}

/*
** `ft_printf` entry point of the project. Reproduces the main features of
** the real `printf` from `stdio.h`. Have a look at the README for more.
*/

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	int				ret;

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				putchar_and_increment_ret(format[++i], &ret);
			else
				handle_dir(format + i, &ap, &i, &ret);
		}
		else
			putchar_and_increment_ret(format[i], &ret);
	}
	va_end(ap);
	return (ret);
}
