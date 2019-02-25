/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:26:03 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 18:08:05 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*handle_null_string(t_dir *cur_dir)
{
	char			*res;

	if (!(res = (char*)malloc(7)))
		exit(-1);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = 0;
	if (ft_strlen(res) > (unsigned long)cur_dir->precision)
		res = ft_strsub(res, 0, cur_dir->precision);
	return (res);
}

/*
** If cur_dir->precision == -1, after cast into unsigned long, it's a big value
** so we surely go in the `else` branch of the statement.
*/

static char		*handle_non_null_string(char *str, t_dir *cur_dir)
{
	char			*res;

	if (ft_strlen(str) > (unsigned long)cur_dir->precision)
		res = ft_strsub(str, 0, cur_dir->precision);
	else
		res = ft_strdup(str);
	return (res);
}

char			*handle_string(char *str, t_dir *cur_dir)
{
	char			*res;
	int				width_extension_len;

	if (!str)
		res = handle_null_string(cur_dir);
	else
		res = handle_non_null_string(str, cur_dir);
	if (cur_dir->width != -1 && (unsigned long)cur_dir->width > ft_strlen(res))
	{
		width_extension_len = cur_dir->width - ft_strlen(res);
		res = handle_width(res, cur_dir, width_extension_len);
	}
	return (res);
}
