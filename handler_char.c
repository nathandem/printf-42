/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:25:36 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 09:45:40 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_char(char c, t_dir *cur_dir)
{
	char			*res;
	int				width_extension_len;

	if (!(res = (char*)malloc(2)))
		exit(-1);
	res[0] = c;
	res[1] = 0;
	if (cur_dir->width > 1)
	{
		width_extension_len = cur_dir->width - 1;
		res = handle_width(res, cur_dir, width_extension_len);
	}
	return (res);
}
