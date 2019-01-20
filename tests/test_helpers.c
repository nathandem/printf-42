/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:08:07 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/20 18:41:08 by nde-maes         ###   ########.fr       */
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
		free(cur_dir);
		return ;
	}

	if (cur_dir->hash != -1)
		printf("hash: %d\n", cur_dir->hash);
	if (cur_dir->zero != -1)
		printf("zero: %d\n", cur_dir->zero);
	if (cur_dir->neg_sign != -1)
		printf("neg_sign: %d\n", cur_dir->neg_sign);
	if (cur_dir->pos_sign != -1)
		printf("pos_sign: %d\n", cur_dir->pos_sign);
	if (cur_dir->space != -1)
		printf("space: %d\n", cur_dir->space);
	if (cur_dir->min_width != -1)
		printf("min_width: %d\n", cur_dir->min_width);
	if (cur_dir->precision != -1)
		printf("precision: %d\n", cur_dir->precision);
	if (cur_dir->size != -1)
		printf("size: %d\n", cur_dir->size);
	printf("type: %c\n\n", cur_dir->type);

	free(cur_dir);
}
