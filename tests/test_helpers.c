/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:08:07 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/04 15:06:20 by nde-maes         ###   ########.fr       */
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
	if (cur_dir->width != -1)
		printf("min_width: %d\n", cur_dir->width);
	if (cur_dir->precision != -1)
		printf("precision: %d\n", cur_dir->precision);
	if (cur_dir->size != NONE)
		printf("size: %d\n", cur_dir->size);
	printf("type: %c\n\n", cur_dir->type);

	free(cur_dir);
}

/*
** This function could work in case the function I'm testing retuns a string,
** yet `printf` prints the resulting string on stdout and retuns an int
** representing the number of characters it has output on stdout.
** Not so useful then...
*/

void				assert_equal(char *test, char *ref)
{
	if (!(ft_strcmp(test, ref)))
		printf("KO - %s =/= %s\n", test, ref);
	else
		printf("OK - %s == %s\n", test, ref);
}
