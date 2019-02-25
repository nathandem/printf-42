/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:22:59 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 15:00:18 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If the number comes with an applicable `0` in its directive (`0` flag and
** no precision - a precision of 0 is a precision).
** 1) If the number is negative, remove its negative sign; otherwise, it'd
**    end up after the added 0s of the width (which is not good).
** 2) Add width if needed. Note that width doesn't include the sign placed
**    before the numbers (`-` if the number is negative, ` ` if a positive
**    number comes with a ` ` flag, `+` if a positive number comes with a `+`
**    flag), so it's removed in the count of the width len to be added.
** 3) Apply the sign, and restore the sign if the number is a negative one.
*/

static char		*handle_signed_flags_zero(char *res, t_dir *cur_dir, int n)
{
	int				res_len;
	int				width_extension_len;

	if (n < 0)
		res = ft_strsub(res, 1, ft_strlen(res) - 1);
	res_len = ft_strlen(res);
	if (cur_dir->width > res_len)
	{
		width_extension_len = cur_dir->width - res_len;
		if (n < 0 || (n > 0 && (cur_dir->pos_sign || cur_dir->space)))
			width_extension_len--;
		res = handle_width(res, cur_dir, width_extension_len);
	}
	res = handle_sign_mark(res, cur_dir, n);
	res = (n < 0) ? realloc_with_add_on_left(res, "-") : res;
	return (res);
}

/*
** If the number comes with a directive without an applicable `0` (not the
** directive `0` or with a precision - a precision of 0 is a valid precision).
** 1) Takes care of the sign.
** 2) Add width if needed. Note that, as opposed to what is the case when the
**    number comes with a valid `0` directive, width counts the `+` and ` `
**    placed before the number.
*/

static char		*handle_signed_flags(char *res, t_dir *cur_dir, int n_shape)
{
	int				res_len;
	int				width_extension_len;

	res = handle_sign_mark(res, cur_dir, n_shape);
	res_len = ft_strlen(res);
	if (cur_dir->width > res_len)
	{
		width_extension_len = cur_dir->width - res_len;
		res = handle_width(res, cur_dir, width_extension_len);
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
	if (cur_dir->zero && cur_dir->precision == -1)
		res = handle_signed_flags_zero(res, cur_dir, n_shape);
	else
		res = handle_signed_flags(res, cur_dir, n_shape);
	return (res);
}
