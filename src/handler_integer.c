/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:42:15 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/18 10:31:56 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_signed_integer(long long n, t_dir *cur_dir)
{
	char			*res;

	res = signed_dec_to_str(n, cur_dir->size);
	res = handle_integer(res, cur_dir);
	return (res);
}

char			*handle_unsigned_integer(unsigned long long n, t_dir *cur_dir)
{
	char			*res;

	if (cur_dir->type == 'u')
		res = unsigned_to_str(n, 10, cur_dir->size, 0);
	else if (cur_dir->type == 'o')
		res = unsigned_to_str(n, 8, cur_dir->size, 0);
	else if (cur_dir->type == 'x')
		res = unsigned_to_str(n, 16, cur_dir->size, 0);
	else if (cur_dir->type == 'X')
		res = unsigned_to_str(n, 16, cur_dir->size, 1);
	else if (cur_dir->type == 'p')
		res = unsigned_to_str(n, 16, 3, 0);
	res = handle_integer(res, cur_dir);
	return (res);
}

char			*handle_integer(char *res, t_dir *cur_dir)
{
	int				res_len;
	char			*tmp_str;
	int				tmp_str_len;
	int				width_extension_len;

	res_len = ft_strlen(res);
	if (cur_dir->precision != -1)
	{
		if (cur_dir->precision == 0 && n == 0)
		{
			free(res);
			res = create_str_of_len_char(0, 1);
		}
		if (cur_dir->precision > res_len)
		{
			tmp_str_len = cur_dir->precision - res_len;
			tmp_str = create_str_of_len_char('0', tmp_str_len);
			res = realloc_with_add_on_left(res, tmp_str);
			free(tmp_str);
		}
	}

	if (cur_dir->type == 'd' || cur_dir->type == 'i')
		handle_sign_mark(res, cur_dir, n);

	res_len = ft_strlen(res);
	if (cur_dir->hash && cur_dir->type == 'o' && n != 0)
		res_len += 1;
	if ((cur_dir->hash && n != 0 && (cur_dir->type == 'x'
					|| cur_dir->type == 'X')) || cur_dir->type == 'p')
		res_len = res_len + 2;

	width_extension_len = 0;
 	if (cur_dir->width != -1 && cur_dir->width > res_len
			&& cur_dir->width > cur_dir->precision)
		width_extension_len = cur_dir->width - ((res_len > cur_dir->precision) ?
			res_len : cur_dir->precision);
	
	if (!cur_dir->zero || cur_dir->precision != -1)
		res = handle_hash(res, cur_dir, n);
	if (width_extension_len)
		res = handle_width(res, cur_dir, width_extension_len);
	if (cur_dir->zero && cur_dir->precision == -1)
		res = handle_hash(res, cur_dir, n);

	return (res);
}
