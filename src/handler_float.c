/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:50:30 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 12:02:24 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int		ft_power(int n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

static char		*get_number(double f, long long whole_int,
					char *whole_str, t_dir *cur_dir)
{
	long long		precision;
	long long		dec_int;
	char			*dec_str;
	char			*res;

	if (!cur_dir->precision)
		res = whole_str;
	else
	{
		precision = (cur_dir->precision == -1) ? 6 : cur_dir->precision;
		precision = ft_power(10, precision);
		dec_int = ABS((long long)((f - whole_int) * precision));
		dec_str = signed_dec_to_str(dec_int);
		res = ft_strnjoin(3, whole_str, ".", dec_str);
		free(dec_str);
	}
	return (res);
}

/*
** `handle_float` takes care of turning a float into a string, doing the
** necessary adjustments to fit the directive flags.
**
** How is the float handled?
** First of, the whole/integer part of the float is extracted and converted into
** a string (`whole_str`). E.g. for `3.14` we get "3".
** Then, if the precision is not `0`, we deal with the decimal part. We single
** it out from the whole part and multiply it by 10 to the power of the
** precision number. E.g. for `3.14` and a precision of 4, that's `1400`.
** We join the 2 parts with a '.' in the middle. E.g. given the whole strings
** "3" and the decimal string "1400", we get "3.1400".
** Eventually, we takes care of the minimum field width. I.e. we add spaces
** before, or zeros before, or spaces after the resulting string to reach the
** width precision. This step is the same for the other conversions.
*/

char			*handle_float(double f, t_dir *cur_dir)
{
	int				width_extension_len;
	long long		whole_int;
	char			*whole_str;
	char			*res;

	whole_int = (long long)f;
	whole_str = signed_dec_to_str(whole_int);
	whole_str = handle_sign_mark(whole_str, cur_dir, whole_int);
	res = get_number(f, whole_int, whole_str, cur_dir);
	if (cur_dir->width != -1)
	{
		width_extension_len = cur_dir->width - (int)ft_strlen(res);
		res = handle_width(res, cur_dir, whole_int);
	}
	free(whole_str);
	return (res);
}
