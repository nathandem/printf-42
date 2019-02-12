/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:50:30 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/12 18:32:05 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int				ft_power(int n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

char			*handle_float(double f, t_dir *cur_dir)
{
	long long		tmp;
	int				tmp2;
	char			*whole_str;
	char			*dec_str;
	char			*res;

	// if int part is 0, need to have `0` explicit -> e.g. `0.14`
	tmp = (long long)f;
	whole_str = signed_dec_to_str(tmp, 4);
	handle_sign_mark(whole_str, cur_dir, tmp);
	
	printf("whole_str: %s\n", whole_str);

	if (!cur_dir->precision)
		res = whole_str;
	else
	{
		tmp2 = (cur_dir->precision == -1) ? 6 : cur_dir->precision;
		tmp2 = ft_power(10, tmp2);
		tmp = ABS((long long)((f - tmp) * tmp2));
		printf("whole_str (before dec_str assignment): %s\n", whole_str);
		dec_str = signed_dec_to_str(tmp, 4); // what's going wrong here?!
		printf("whole_str (after dec_str assigment): %s\n", whole_str);
		printf("dec_str: %s\n", dec_str);
		res = ft_strnjoin(3, whole_str, ".", dec_str);
		free(dec_str);
	}

	if (cur_dir->width != -1)
	{
		tmp = ft_strlen(res);
		tmp = cur_dir->width - tmp;
		res = handle_width(res, cur_dir, tmp);
	}

	// free(whole_str);
	return (res);
}
