/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:26:03 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/18 14:46:02 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If the string is null returns "(null)".
*/

char			*handle_null_string(void)
{
	char			*res;

	if (!(res = (char*)malloc(7)))
		exit(1);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = 0;
	return (res);
}

/*
** `handle_string` receives a string and a parsed directive as inputs, does the
** proper formating.
**
** Note: because the util `ft_strlen` returns an unsigned value, it can't be
** compared to a signed one. Most compilers perform an implicit cast of the
** signed value into an unsigned, which compilely twist the result. Here, it
** meant that cur_dir->width with its default value of -1 was bigger than any
** reasonable length of `ft_strlen(char*)`. Had to add `cur_dir->width != -1`
** to make the signed value which would be compared wouldn't end up in the upper
** range of the unsigned values.
*/

char			*handle_string(char *str, t_dir *cur_dir)
{
	char			*res;
	int				width_extension_len;

	if (!str)
	{
		res = handle_null_string();
		return (res);
	}
	if (cur_dir->precision != -1
		&& ft_strlen(str) > (unsigned long)cur_dir->precision)
		res = ft_strsub(str, 0, cur_dir->precision);
	else
		res = ft_strdup(str);

	if (cur_dir->width != -1 && (unsigned long)cur_dir->width > ft_strlen(res))
	{
		width_extension_len = cur_dir->width - ft_strlen(res);
		res = handle_width(res, cur_dir, width_extension_len);
	}
	return (res);
}
