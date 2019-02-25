/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_generics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 08:52:00 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 10:11:42 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** `handle_sign_mark` adds an optional sign mark on value which need it.
** The ` ` (space) flag adds a space before any signed value.
** The `+` flag adds a `+` before any signed value.
** If both flags are present, `+` takes the precedence.
**
** Note: only signed numeric values are concerned, that's to say the three
** conversions d, i (decimal integer) and f (float).
*/

char			*handle_sign_mark(char *res, t_dir *cur_dir, int n_shape)
{
	if (cur_dir->space && !cur_dir->pos_sign && n_shape >= 0)
		res = realloc_with_add_on_left(res, " ");
	if (cur_dir->pos_sign && n_shape >= 0)
		res = realloc_with_add_on_left(res, "+");
	return (res);
}

/*
** `handle_hash` applies the effect of the `#` flag to the conversions on which
** it applies, i.e. `o`, `x` and `X`.
** For `o`, it prepends `O` before the result, if the result is not 0.
** For `x`, it prepends `Ox` before the result, if the result is not 0.
** For `X`, it prepends `0X` before the result, if the result is not 0.
*/

char			*handle_hash(char *res, t_dir *cur_dir, int n_shape)
{
	if (cur_dir->hash)
	{
		if (cur_dir->type == 'o')
		{
			if (res == 0 || res[0] == '0')
				res[0] = '0';
			else
				res = realloc_with_add_on_left(res, "0");
		}
		if (cur_dir->type == 'x' && n_shape)
			res = realloc_with_add_on_left(res, "0x");
		if (cur_dir->type == 'X' && n_shape)
			res = realloc_with_add_on_left(res, "0X");
	}
	if (cur_dir->type == 'p')
		res = realloc_with_add_on_left(res, "0x");
	return (res);
}

/*
** `handle_width` reflects the effect of a minimum width field to the conversion
** which specifies a width greater than the length of their result.
**
** Note: this function should be called only if the result needs to be
** transformed to accomodated a width. The number of characters to add to reach
** that width should be calculated upfront and passed as `tmp_len`.
*/

char			*handle_width(char *res, t_dir *cur_dir, int tmp_len)
{
	char			*tmp_str;

	if (cur_dir->zero && !cur_dir->neg_sign && cur_dir->precision == -1)
	{
		tmp_str = create_str_of_len_char('0', tmp_len);
		res = realloc_with_add_on_left(res, tmp_str);
	}
	else if (cur_dir->neg_sign)
	{
		tmp_str = create_str_of_len_char(' ', tmp_len);
		res = realloc_with_add_on_right(res, tmp_str);
	}
	else
	{
		tmp_str = create_str_of_len_char(' ', tmp_len);
		res = realloc_with_add_on_left(res, tmp_str);
	}
	free(tmp_str);
	return (res);
}

char			*handle_precision(char *res, t_dir *cur_dir, int n_shape)
{
	int				res_len;
	char			*tmp_str;
	int				tmp_str_len;

	res_len = (n_shape < 0) ? ft_strlen(res) - 1 : ft_strlen(res);
	if (cur_dir->precision != -1)
	{
		if (cur_dir->precision == 0 && n_shape == 0)
		{
			free(res);
			res = create_str_of_len_char(0, 1);
		}
		if (cur_dir->precision > res_len)
		{
			tmp_str_len = cur_dir->precision - res_len;
			(n_shape < 0) ? res = ft_strsub(res, 1, ft_strlen(res) - 1) : 0;
			tmp_str = create_str_of_len_char('0', tmp_str_len);
			res = realloc_with_add_on_left(res, tmp_str);
			res = (n_shape < 0) ? realloc_with_add_on_left(res, "-") : res;
			free(tmp_str);
		}
	}
	return (res);
}
