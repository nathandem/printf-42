/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive_parsers-1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:58:09 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 18:17:26 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** `initialize_a_dir` initializes a structure containing the result of the
** parsing of a directive. By default, all interger values are set to `-1`,
** except len which is set to `1` (because there's at least `%` in the directive
** when the `parse_dir` function is called). The default type for the
** conversion is set to `.`.
*/

t_dir				*initialize_a_dir(void)
{
	t_dir				*cur_dir;

	if (!(cur_dir = (t_dir*)malloc(sizeof(t_dir))))
		exit(-1);
	cur_dir->hash = 0;
	cur_dir->zero = 0;
	cur_dir->neg_sign = 0;
	cur_dir->pos_sign = 0;
	cur_dir->space = 0;
	cur_dir->width = -1;
	cur_dir->precision = -1;
	cur_dir->size = NONE;
	cur_dir->type = '.';
	cur_dir->len = 1;
	return (cur_dir);
}

void				clean_dir_from_unsupported_flags(t_dir *cur_dir)
{
	if (cur_dir->type == 'c' || cur_dir->type == 's' || cur_dir->type == 'p')
		cur_dir->size = NONE;
	if (cur_dir->type == 'c')
		cur_dir->precision = -1;
	if (cur_dir->type != 'f' && cur_dir->size == L)
		cur_dir->size = NONE;
	if (cur_dir->type == 'f' && (cur_dir->size == hh || cur_dir->size == h
		|| cur_dir->size == ll))
		cur_dir->size = NONE;
}

/*
** I: char *str is the pointer to the beginning of the directive to handle
**    (the pointer points to the `%` sign)
** O: a `t_dir` filled with the result of the parsing
**    Returning a t_dir with a type of `.` means the directive is invalid.
**
** Form of a directive: %[flags][width][.precision][size]type
** Given this structure, our parser handle the segments of the directive one
** at the time.
**
** Note: `parse_dir` must be called with a char pointer pointing on a `%` char.
*/

t_dir				*parse_dir(const char *str)
{
	int					i;
	t_dir				*cur_dir;

	cur_dir = initialize_a_dir();
	i = 1;
	parse_flags(str, cur_dir, &i);
	parse_width(str, cur_dir, &i);
	parse_precision(str, cur_dir, &i);
	parse_size(str, cur_dir, &i);
	parse_conversion(str, cur_dir, &i);
	clean_dir_from_unsupported_flags(cur_dir);
	cur_dir->len = i;
	return (cur_dir);
}
