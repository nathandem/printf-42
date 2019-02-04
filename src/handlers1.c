/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:42:15 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/04 18:47:56 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// make handling functions for csp and floats

#include <stdio.h>
void			handle_integer(long long n, t_dir *cur_dir)
{
	char			*nb;
	int				nb_len;
	char			*tmp_str;
	int				tmp_str_len;

	// `n` needs to be cast in the correct type when sent to conversion function
	if (cur_dir->type == 'd' || cur_dir->type == 'i')
		nb = signed_dec_to_str((t_ull)n, cur_dir->size);
	else if (cur_dir->type == 'u')
		nb = unsigned_to_str((t_ull)n, 10, cur_dir->size, 0);
	else if (cur_dir->type == 'o')
		nb = unsigned_to_str((t_ull)n, 8, cur_dir->size, 0);
	else if (cur_dir->type == 'x')
		nb = unsigned_to_str((t_ull)n, 16, cur_dir->size, 0);
	else
		nb = unsigned_to_str((t_ull)n, 16, cur_dir->size, 1);
	nb_len = ft_strlen(nb);

	if (cur_dir->precision != -1)
	{
		if (cur_dir->precision == 0 && n == 0)
		{
			free(nb);
			nb = create_str_of_len_char(0, 1);
		}
		if (cur_dir->precision > nb_len)
		{
			tmp_str_len = cur_dir->precision - nb_len;
			tmp_str = create_str_of_len_char('0', tmp_str_len);
			nb = realloc_with_add_on_left(nb, tmp_str);
			free(tmp_str);
		}
	}

	if (cur_dir->type == 'd' || cur_dir->type == 'i')
	{
		if (cur_dir->space && !cur_dir->pos_sign)
			nb = realloc_with_add_on_left(nb, " ");
		if (cur_dir->pos_sign && n >= 0)
			nb = realloc_with_add_on_left(nb, "+");
	}

	if ((cur_dir->type == 'o' || cur_dir->type == 'x' || cur_dir->type == 'X')
		&& cur_dir->hash)
	{
		if (cur_dir->type == 'o')
			nb = realloc_with_add_on_left(nb, "0");
		else if (cur_dir->type == 'x')
			nb = realloc_with_add_on_left(nb, "0x");
		else if (cur_dir->type == 'X')
			nb = realloc_with_add_on_left(nb, "0X");
	}
 
	nb_len = ft_strlen(nb);
	if (cur_dir->width != -1 && cur_dir->width > nb_len
		&& cur_dir->width > cur_dir->precision)
	{
		tmp_str_len = cur_dir->width - ((nb_len > cur_dir->precision) ?
				nb_len : cur_dir->precision);
		if (cur_dir->zero && !cur_dir->neg_sign && cur_dir->precision == -1)
		{
			tmp_str = create_str_of_len_char('0', tmp_str_len);
			nb = realloc_with_add_on_left(nb, tmp_str);
			free(tmp_str);
		}
		else if (cur_dir->neg_sign)
		{
			tmp_str = create_str_of_len_char(' ', tmp_str_len);
			nb = realloc_with_add_on_right(nb, tmp_str);
			free(tmp_str);
		}
		else
		{
			tmp_str = create_str_of_len_char(' ', tmp_str_len);
			nb = realloc_with_add_on_left(nb, tmp_str);
			free(tmp_str);
		}
	}
	// should we print here or elsewhere?
	write(1, nb, ft_strlen(nb));
}
