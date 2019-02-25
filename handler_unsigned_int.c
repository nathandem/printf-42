/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:42:15 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 12:28:37 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** `handle_unsigned_flags` deals with the precision, width and flags of
** unsigned integers. That task is mostly common for all conversions, with some
** exceptions like how to handle of the `#` flag which is only supported by
** `o`, `x` and `X` conversions or how to treat the `0` flag.
*/

static char		*handle_unsigned_flags(char *res, t_dir *cur_dir, int n_shape)
{
	int				res_len;
	int				width_extension_len;

	res = handle_precision(res, cur_dir, n_shape);
	res_len = ft_strlen(res);
	if (cur_dir->hash && cur_dir->type == 'o' && n_shape)
		res_len += 1;
	if ((cur_dir->hash && n_shape && (cur_dir->type == 'x'
			|| cur_dir->type == 'X')) || cur_dir->type == 'p')
		res_len = res_len + 2;
	width_extension_len = 0;
	if (cur_dir->width != -1 && cur_dir->width > res_len
			&& cur_dir->width > cur_dir->precision)
		width_extension_len = cur_dir->width - ((res_len > cur_dir->precision) ?
			res_len : cur_dir->precision);
	if (!cur_dir->zero || cur_dir->precision != -1)
		res = handle_hash(res, cur_dir, n_shape);
	if (width_extension_len)
		res = handle_width(res, cur_dir, width_extension_len);
	if (cur_dir->zero && cur_dir->precision == -1)
		res = handle_hash(res, cur_dir, n_shape);
	return (res);
}

/*
** `handle_unsigned_integer` is the entry point of several conversions:
** - `u`: unsigned int in base 10
** - `o`: unsigned int in base 8
** - `x` and `X`: unsigned int in base 16
** - `p`: memory address, basically just an hexa integer
*/

char			*handle_unsigned_integer(unsigned long long n, t_dir *cur_dir)
{
	char			*res;
	int				n_shape;

	n_shape = (n == 0) ? 0 : 1;
	if (cur_dir->type == 'u')
		res = unsigned_to_str(n, 10, 0);
	if (cur_dir->type == 'o')
		res = unsigned_to_str(n, 8, 0);
	if (cur_dir->type == 'x')
		res = unsigned_to_str(n, 16, 0);
	if (cur_dir->type == 'X')
		res = unsigned_to_str(n, 16, 1);
	if (cur_dir->type == 'p')
		res = unsigned_to_str(n, 16, 0);
	res = handle_unsigned_flags(res, cur_dir, n_shape);
	return (res);
}
