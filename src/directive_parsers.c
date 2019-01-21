/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:58:09 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/22 14:22:45 by nde-maes         ###   ########.fr       */
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
		exit(1);
	cur_dir->hash = -1;
	cur_dir->zero = -1;
	cur_dir->neg_sign = -1;
	cur_dir->pos_sign = -1;
	cur_dir->space = -1;
	cur_dir->min_width = -1;
	cur_dir->precision = -1;
	cur_dir->size = -1;
	cur_dir->type = '.';
	cur_dir->len = 1;
	return (cur_dir);
}

/*
** I: char *str is the pointer to the beginning of the directive to handle
**    (the pointer points to the `%` sign)
** O: a `t_dir` filled with the result of the parsing
**    Returning a t_dir with a type of `.` means the directive is invalid.
**
** Form of a directive: %[flags][width][.precision][size]type
** Given this regular structure, our parser handle the segments of the
** directive one at the time.
**
** Note: `parse_dir` must be called with a char pointer pointing on a `%` char.
*/

t_dir				*parse_dir(const char *str)
{
	int					i;
	t_dir				*cur_dir;

	cur_dir = initialize_a_dir();
	i = 1;
	// handle flags, possible chars: #0- +
	// end of the flag when width (digit), or precision (introduced by a `.`),
	// or size (either h, hh, l, ll or L), or type (csp diouxX f), or `%` reached
	// if none of the 5 above, make the program exit because it's an error
	// -> hopefully, flags are distict from the following elements of the directive
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == ' ' ||
			str[i] == '+')
	{
		if (str[i] == '#')
			cur_dir->hash = 1;
		else if (str[i] == '0')
			cur_dir->zero = 1;
		else if (str[i] == '-')
			cur_dir->neg_sign = 1;
		else if (str[i] == ' ')
			cur_dir->space = 1;
		else if (str[i] == '+')
			cur_dir->pos_sign = 1;
		i++;
	}

	// handle width
	// handling is pretty easy, width can only be digits
	// it may be followed by a precision (`.` then some digits),
	// a size (h, hh, l, ll, L) and must be terminated by a conversion
	// (csp diouxX f), or the special case `%`
	// note: it's enough for the `0` flag to appear once before to have the
	// min width behaves as if the `0` flag is placed just ahead of it
	if (ft_isdigit(str[i]))
	{
		cur_dir->min_width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}

	// handle precision (start with a `.`)
	// note: unlike other elements of the directive, an "empty" precision
	// (i.e. `.` or `.0` doesn't mean zero)
	// Yet, the fact that we run atoi if a dot is met guarantees that, in this
	// case, the precision is set at 0 or more (not the default `-1` value).
	// TO BE CONFIRMED BY TESTS
	if (str[i] == '.')
	{
		i++;
		cur_dir->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}

	// handle size flags
	// possible values: hh, h, l, ll, L
	// respective meaning: signed char, signed short, signed long,
	// signed long long and long double
	// respectively stored in the structure as 1, 2, 3, 4, 5
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
	{
		if (str[i] == 'h')
		{
			if (str[i + 1] == 'h')
			{
				i++;
				cur_dir->size = 1;
			}
			else
				cur_dir->size = 2;
		}

		else if (str[i] == 'l')
		{
			if (str[i + 1] == 'l')
			{
				i++;
				cur_dir->size = 4;
			}
			else
				cur_dir->size = 3;
		}

		else if (str[i] == 'L')
			cur_dir->size = 5;

		i++;
	}

	// handle type conversion
	// possible values: csp diouxX f
	// -> make the global array of struct to map type to a function
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'x' ||
		str[i] == 'X' || str[i] == 'f')
	{
		cur_dir->type = str[i];
		i++;
	}

	cur_dir->len = i;

	return (cur_dir);
}
