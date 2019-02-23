/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:42:15 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/23 19:27:02 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_signed_integer(long long n, t_dir *cur_dir)
{
	char			*res;
	int				n_shape;
	int				res_len;
	int				width_extension_len;

	if (n == 0)
		n_shape = 0;
	else
		n_shape = (n > 0) ? 1 : -1;
	res = signed_dec_to_str(n, cur_dir->size);
	res = handle_precision(res, cur_dir, n_shape);

	if (!cur_dir->zero || cur_dir->precision > -1)
		res = handle_sign_mark(res, cur_dir, n_shape);
	if (n < 0 && cur_dir->zero && cur_dir->precision == -1)
		res = ft_strsub(res, 1, ft_strlen(res) - 1);

	res_len = ft_strlen(res);
	if (cur_dir->width > res_len)
	{
		width_extension_len = cur_dir->width - res_len;
		if (cur_dir->zero && ((cur_dir->space || cur_dir->pos_sign) || n < 0))
			width_extension_len--;
		res = handle_width(res, cur_dir, width_extension_len);
	}

	if (cur_dir->zero && cur_dir->precision == -1)
	{
		res = handle_sign_mark(res, cur_dir, n_shape);
		res = (n_shape < 0) ? realloc_with_add_on_left(res, "-") : res;
	}

	return (res);
}

// n_shape possible values: -1 (if n < 0), 0 (if n == 0), 1 (if n > 0)
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

char			*handle_unsigned_integer(unsigned long long n, t_dir *cur_dir)
{
	char			*res;
	int				n_shape;

	n_shape = (n == 0) ? 0 : 1;
	if (cur_dir->type == 'u')
		res = unsigned_to_str(n, 10, cur_dir->size, 0);
	else if (cur_dir->type == 'o')
		res = unsigned_to_str(n, 8, cur_dir->size, 0);
	else if (cur_dir->type == 'x')
		res = unsigned_to_str(n, 16, cur_dir->size, 0);
	else if (cur_dir->type == 'X')
		res = unsigned_to_str(n, 16, cur_dir->size, 1);
	else
		res = unsigned_to_str(n, 16, 3, 0);
	res = handle_unsigned_flags(res, cur_dir, n_shape);
	return (res);
}
