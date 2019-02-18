/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:08:07 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/19 10:12:51 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

void				display_t_dir(t_dir *cur_dir)
{
	printf("len: %d\n", cur_dir->len);

	if (cur_dir->type == '.')
	{
		printf("INVALID DIR\n\n");
		// free(cur_dir);
		return ;
	}

	if (cur_dir->hash)
		printf("hash: %d\n", cur_dir->hash);
	if (cur_dir->zero)
		printf("zero: %d\n", cur_dir->zero);
	if (cur_dir->neg_sign)
		printf("neg_sign: %d\n", cur_dir->neg_sign);
	if (cur_dir->pos_sign)
		printf("pos_sign: %d\n", cur_dir->pos_sign);
	if (cur_dir->space)
		printf("space: %d\n", cur_dir->space);
	if (cur_dir->width != -1)
		printf("min_width: %d\n", cur_dir->width);
	if (cur_dir->precision != -1)
		printf("precision: %d\n", cur_dir->precision);
	if (cur_dir->size != NONE)
		printf("size: %d\n", cur_dir->size);
	printf("type: %c\n\n", cur_dir->type);

	// free(cur_dir);
}
