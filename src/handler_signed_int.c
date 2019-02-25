/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:22:59 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 12:01:50 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** `handle_signed_flags` contains the complexity of dealing with `0` flag
** depending whether there's also a precision, the value is negative.
*/

static char		*handle_signed_flags(char *res, t_dir *cur_dir, int n_shape)
{
	int				res_len;
	int				width_extension_len;

	if (!cur_dir->zero || cur_dir->precision > -1)
		res = handle_sign_mark(res, cur_dir, n_shape);
	if (n_shape < 0 && cur_dir->zero && cur_dir->precision == -1)
		res = ft_strsub(res, 1, ft_strlen(res) - 1);
	res_len = ft_strlen(res);
	if (cur_dir->width > res_len)
	{
		width_extension_len = cur_dir->width - res_len;
		if (cur_dir->zero && ((cur_dir->space || cur_dir->pos_sign)
					|| n_shape < 0))
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

char			*handle_signed_integer(long long n, t_dir *cur_dir)
{
	char			*res;
	int				n_shape;

	if (n == 0)
		n_shape = 0;
	else
		n_shape = (n > 0) ? 1 : -1;
	res = signed_dec_to_str(n);
	res = handle_precision(res, cur_dir, n_shape);
	res = handle_signed_flags(res, cur_dir, n_shape);
	return (res);
}
