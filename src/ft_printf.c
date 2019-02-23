/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:50:54 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/23 17:36:31 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "d2h.h"

static void		handle_dir_pourcent(t_dir *cur_dir, int *pos, int *ret)
{
	char			*str;

	str = handle_pourcent(cur_dir);

	ft_putstr(str);

	*pos += (cur_dir->len - 1);
	*ret += (int)ft_strlen(str);
	free(str);
	free(cur_dir);
	return ;
}

static void		handle_dir_char(t_dir *cur_dir, va_list *ap, int *pos, int *ret)
{
	char			*str;
	char			c;

	c = (char)va_arg(*ap, int);
	str = handle_char(c, cur_dir);

	ft_putstr(str);
	if (c == 0)
		write(1, &c, 1);

	*pos += (cur_dir->len - 1);
	*ret += (int)ft_strlen(str);
	(c == 0) ? (*ret)++ : 0;
	free(str);
	free(cur_dir);
	return ;
}

static void		handle_dir(const char *dir, va_list *ap, int *pos, int *ret)
{
	t_dir			*cur_dir;
	char			*str;
	int				i;

	// where the parsing of the directive takes place
	// tests some invalid cases (missing conversion flag for instance)
	cur_dir = parse_dir(dir);
	if (cur_dir->type == '.')
	{
		*pos += cur_dir->len;
		free(cur_dir);
		return ;
	}

	if (cur_dir->type == 'c')
		return (handle_dir_char(cur_dir, ap, pos, ret));
	if (cur_dir->type == '%')
		return (handle_dir_pourcent(cur_dir, pos, ret));

	// where the value and the directive are routed to the proper handler
	i = -1;
	while (++i < 34)
	{
		if ((g_d2h[i].type == cur_dir->type)
		&& (g_d2h[i].size == cur_dir->size))
			str = g_d2h[i].ft_d2h(ap, cur_dir);
	}

	// print out the result
	ft_putstr(str);

	// eventually, free (no leak)
	*pos += (cur_dir->len - 1);
	*ret += (int)ft_strlen(str);
	free(str);
	free(cur_dir);
	return ;
}

/*
** Just a trick on the Norm to get ft_printf fits in 25 lines max.
** It's ugly, I know.
*/

static void		putchar_and_increment_ret(char c, int *ret)
{
	ft_putchar(c);
	(*ret)++;
}

/*
** `ft_printf` entry point of the project. Reproduces the main features of
** the real `printf` from `stdio.h`.
*/

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;
	int				ret;

	i = -1;
	ret = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			handle_dir(format + i, &ap, &i, &ret);
		else
			putchar_and_increment_ret(format[i], &ret);
	}
	va_end(ap);
	return (ret);
}
