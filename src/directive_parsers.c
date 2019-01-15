/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:58:09 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/15 19:10:33 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_dir				*initialize_a_dir(void)
{
	t_dir				*cur_dir;

	if (!(cur_dir = (t_dir*)malloc(sizeof(t_dir))))
		exit(1);
	cur_dir->hash = 0;
	cur_dir->zero = 0;
	cur_dir->neg_sign = 0;
	cur_dir->pos_sign = 0;
	cur_dir->space = 0;
	cur_dir->min_width = 0;
	cur_dir->precision = 0;
	cur_dir->size = 0;
	cur_dir->char = 0;
	return (cur_dir);
}

/*
** I: char *str is the pointer to the beginning of the directive to handle
**    ( the `%` sign) OR WITHOUT
** O: a t_directive filled with the result of the parsing
**
** Form of a directive: %[flags][width][.precision][size]type
** Given this regular structure, our parser handle one of segment of the
** directive at the time.
*/


	// TODO before doing stuff below, for type handling
	// ==> CREATE TEST FILES WITH SIMPLE, MEDIUM AND COMPLEX CASES
	//     TO MAKE SURE THIS PARSE_DIR FUNCTION WORKS WELL
	//     note: the program should exits if the format is invalid,
	//           we should see some exits here
	// Then split this long function into smaller ones, handling
	// only one or two flags.

t_dir				*parse_dir(const char *str)
{
	int					i;
	t_dir				*cur_dir;

	cur_dir = initialize_a_dir();
	i = -1;
	// handle flags, possible chars: #0- +
	// end of the flag when width (digit), or precision (introduced by a `.`),
	// or size (either h, hh, l, ll or L), or type (csp diouxX f), or `%` reached
	// if none of the 5 above, make the program exit because it's an error
	// -> hopefully, flags are distict from the following elements of the directive
	while (str[++i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == ' ' ||
			str[i] == '+')
	{
		if (str[i] == '#'):
			cur_dir->hash = 1;
		if (str[i] == '0'):
			cur_dir->zero = 1;
		if (str[i] == '-'):
			cur_dir->neg_sign = 1;
		if (str[i] == ' '):
			cur_dir->space = 1;
		if (str[i] == '+'):
			cur_dir->pos_sign = 1;
	}

	// handle width
	// handling is pretty easy, width can only be digits
	// it may be followed by a precision (`.` then some digits),
	// a size (h, hh, l, ll, L) and must be terminated by a conversion
	// (csp diouxX f), or the special case `%`
	cur_dir->min_width = ft_atoi(str + i);
	while (ft_isdigit[i])
		i++;

	// handle precision (start with a `.`)
	if (str[i] == '.')
	{
		i++;
		cur_dir->precision = ft_atoi(str + i);
		while (ft_isdigit[i])
			i++;
	}

	// handle size flags
	// possible values: h, hh, l, ll, L
	// respectively stored in the structure as 1, 2, 3, 4, 5
	if (str[i] == 'h')
	{
		if (str[i + 1] = 'h')
		{
			i++;
			cur_dir->size = 2;
		}
		else
			cur_dir->size = 1;
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
	// handle type conversion
	// possible values: csp diouxX f
	// -> make the global array of struct to map type to a function
	cur_dir->type = str[i];


	return (cur_dir);
}
