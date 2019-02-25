/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_int_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:47:38 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 12:06:48 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_signed_base_len(long long n, int base)
{
	int					len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

/*
** `signed_dec_to_str` converts an base-10 signed number stored in an integer,
** or an integer variant (signed char, signed short, signed long or signed
** long long) into a string (i.e. an array of chars, ASCII encoded).
** Edge cases covered here: `0`, asymmetry between min/max.
**
** Parameters:
** - `n` (signed long long): number to return into a string.
**   This value may be "virtually" cast into a small type, if the `size` passed
**   refer to a type smaller than an signed long long.
** - `size` (char): integer variant in which to consider the number
**   Possible values:	0: integer
**						1: char
**						2: short
**						3: long
**						4: long long
**   It is important to flow this type indication because the limits of these
**   types varies in relation to their length. The more bits a type has bigger
**   its min and max values.
**
** Notes:
** - to handle all size flags/all possible inputs safely, `n` type is the
**   uses the largest of them, the `long long`.
** - numbers of bits of each type is platfom specific. On my 64bits macOS, chars
**   are 1 byte long, shorts 2 bytes, integers 4 bytes, long bytes, so are
**   long long.
*/

char				*signed_dec_to_str(long long n)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
	n_abs = ABS(n);
	if (!(number = (char*)malloc(len + 1)))
		exit(-1);
	number[len--] = 0;
	if (n < 0)
		number[0] = '-';
	if (n == 0)
		number[0] = '0';
	while (n_abs)
	{
		number[len--] = (n_abs % 10) + 48;
		n_abs /= 10;
	}
	return (number);
}
