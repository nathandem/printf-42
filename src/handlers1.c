/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:42:15 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/11 11:26:30 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char			*handle_hash(char *res, t_dir *cur_dir, t_ull n)
{
	if (cur_dir->hash && n != 0)
	{
		if (cur_dir->type == 'o' && n != 0)
			res = realloc_with_add_on_left(res, "0");
		if ((cur_dir->type == 'x' && n != 0) || cur_dir->type == 'p')
			res = realloc_with_add_on_left(res, "0x");
		if (cur_dir->type == 'X' && n != 0)
			res = realloc_with_add_on_left(res, "0X");
	}
	if (cur_dir->type == 'p')
		res = realloc_with_add_on_left(res, "0x");
	return (res);
}

char			*handle_width(char *res, int tmp_s_len, t_dir *cur_dir)
{
	char			*tmp_str;

	if (cur_dir->zero && !cur_dir->neg_sign && cur_dir->precision == -1)
	{
		tmp_str = create_str_of_len_char('0', tmp_s_len);
		res = realloc_with_add_on_left(res, tmp_str);
	}
	else if (cur_dir->neg_sign)
	{
		tmp_str = create_str_of_len_char(' ', tmp_s_len);
		res = realloc_with_add_on_right(res, tmp_str);
	}
	else
	{
		tmp_str = create_str_of_len_char(' ', tmp_s_len);
		res = realloc_with_add_on_left(res, tmp_str);
	}
	free(tmp_str);
	return (res);
}

// filter out invalid directives and values before calling this function
void			handle_integer(long long n, t_dir *cur_dir)
{
	char			*res;
	int				res_len;
	char			*tmp_str;
	int				tmp_str_len;
	int				width_extension_len;

	// `n` needs to be cast in the correct type when sent to conversion function
	// for a type `p`, it's an unsigned long
	if (cur_dir->type == 'd' || cur_dir->type == 'i')
		res = signed_dec_to_str((t_ull)n, cur_dir->size);
	else if (cur_dir->type == 'u')
		res = unsigned_to_str((t_ull)n, 10, cur_dir->size, 0);
	else if (cur_dir->type == 'o')
		res = unsigned_to_str((t_ull)n, 8, cur_dir->size, 0);
	else if (cur_dir->type == 'x')
		res = unsigned_to_str((t_ull)n, 16, cur_dir->size, 0);
	else if (cur_dir->type == 'X')
		res = unsigned_to_str((t_ull)n, 16, cur_dir->size, 1);
	else if (cur_dir->type == 'p')
		res = unsigned_to_str((t_ull)n, 16, 3, 0);
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
	{
		if (cur_dir->space && !cur_dir->pos_sign)
			res = realloc_with_add_on_left(res, " ");
		if (cur_dir->pos_sign && n >= 0)
			res = realloc_with_add_on_left(res, "+");
	}

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
		res = handle_width(res, width_extension_len, cur_dir);
	if (cur_dir->zero && cur_dir->precision == -1)
		res = handle_hash(res, cur_dir, n);

	// should we print here or elsewhere?
	write(1, res, ft_strlen(res));
}

void			handle_char(char c, t_dir *cur_dir)
{
	char			*res;
	int				width_extension_len;

	res = (char*)malloc(2);
	res[0] = c;
	res[1] = 0;

	if (cur_dir->width > 1)
	{
		width_extension_len = cur_dir->width - 1;
		res = handle_width(res, width_extension_len, cur_dir);
	}
	write(1, res, ft_strlen(res));
}

/*
** `handle_string` receives a string and a parsed directive as inputs, does the
** proper formating, then print (????) the result.
**
** Note: because the util `ft_strlen` returns an unsigned value, it can't be
** compared to a signed one. Most compilers perform an implicit cast of the
** signed value into an unsigned, which compilely twist the result. Here, it
** meant that cur_dir->width with its default value of -1 was bigger than any
** reasonable length of `ft_strlen(char*)`. Had to add `cur_dir->width != -1`
** to make the signed value which would be compared wouldn't end up in the upper
** range of the unsigned values.
*/

void			handle_string(char *str, t_dir *cur_dir)
{
	char			*res;
	int				width_extension_len;

	if (cur_dir->precision != -1
		&& ft_strlen(str) > (unsigned long)cur_dir->precision)
		res = ft_strsub(str, 0, cur_dir->precision);
	else
		res = ft_strdup(str);

	if (cur_dir->width != -1 && (unsigned long)cur_dir->width > ft_strlen(res))
	{
		width_extension_len = cur_dir->width - ft_strlen(res);
		res = handle_width(res, width_extension_len, cur_dir);
	}

	write(1, res, ft_strlen(res));
}
