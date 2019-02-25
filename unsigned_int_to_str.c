/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_to_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:05:39 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 12:27:20 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_unsigned_base_len(unsigned long long n, int base)
{
	int					len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

/*
** `get_hexa_letter` gives the letter which corresponds to the base-10 value.
** The parameter `maj` tells whether the letter should in capital or not.
** For example: 9 -> 9  |  10 -> a  |  15 -> f
*/

static char			get_hexa_letter(int hex_modulo, int maj)
{
	char				letter;

	if (hex_modulo > 9)
	{
		if (maj)
			letter = hex_modulo + 55;
		else
			letter = hex_modulo + 87;
	}
	else
		letter = hex_modulo + 48;
	return (letter);
}

/*
** `unsigned_to_str` converts an number stored in integer variants
** (i.e. from an unsigned char to an unsigned long long) into a string
** (i.e. an array of ASCII-encoded chars). The number can be passed as a
** base 10, base 8 or 16.
**
** Parameters:
** - `n` (unsigned long long): number to return into a string.
**   This value is cast into a smaller type if the `size` (3rd arg) indicates to
**   so that limits/overflows are kept specific to each type.
** - `base` (char): the base in which the number is to be converted into.
**   Possible choices 10 (C default base), 8, 16
** - `size` (char): integer variant
**   Possible choices: 	0: int, 4 bytes
**						1: char, 1 byte
**						2: short, 2 bytes
**						3: long, 8 bytes
**						4: long long, 4 bytes
** - `cap` (char): whether or not the letters of hexadecimal values should be
**   capitalized
**
** Notes:
** - eventhough numbers are stored in base 2 in the bits of the interger,
**   C provides us with base-10 values. That's why we convert the values from
**   base 10 to base whatever other base the number is in, not from base 2.
** - as pointer addresses are actually just hexadecimal numbers (`%p`),
**   they can also be converted using `unsigned_to_str`.
** - the number of bytes assigned to each integer types varies depending
**   the architecture of the machine.
*/

char				*unsigned_to_str(t_ull n, int base, int cap)
{
	char				*number;
	int					len;

	len = get_unsigned_base_len(n, base);
	if (!(number = (char*)malloc(len + 1)))
		exit(-1);
	number[len--] = 0;
	(n == 0) ? number[0] = '0' : 0;
	while (n)
	{
		if (base == 16)
			number[len--] = get_hexa_letter(n % 16, cap);
		else
			number[len--] = (n % base) + 48;
		n /= base;
	}
	return (number);
}
