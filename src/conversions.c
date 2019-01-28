/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:47:38 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/28 19:59:52 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "ft_printf.h"

/*
** `get_signed_base_len` mesures the length of an int by iteratively chopping
** its units by dividing by its base until the int is worth 0.
*/

int					get_signed_base_len(long long n, int base)
{
	int					len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

/*
** `get_unsigned_base_len` works the same as `get_signed_base_len` except that
** it takes the number to measure as an unsigned long long. This makes no
** difference in all cases, except for 20 figures numbers which can't hold in
** in a signed long long.
*/

int					get_unsigned_base_len(unsigned long long n, int base)
{
	int					len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

/*
** `get_n_ab` "virtually" cast a signed long long int into whatever
** size flag (see `signed_dec_to_str` doc for the correspondances).
** Though the number comes in a long long and is returned in a long long,
** the value stored in these 64bits go have the limits of its type.
** For example, if the size indicates that the type of the number is an int,
** the min and max values of the number will be -(2^32) and (2^32)-1, not
** -(2^64) and (2^64)-1.
*/

unsigned long long	get_n_abs(long long n, char size)
{
	unsigned long long	n_abs;

	if (size == 0)
		n_abs = (n < 0) ? (t_ui)(-n) : (t_ui)n;
	if (size == 1)
		n_abs = (n < 0) ? (t_uc)(-n) : (t_uc)n;
	if (size == 2)
		n_abs = (n < 0) ? (t_us)(-n) : (t_us)n;
	if (size == 3)
		n_abs = (n < 0) ? (t_ul)(-n) : (t_ul)n;
	if (size == 4)
		n_abs = (n < 0) ? (t_ull)(-n) : (t_ull)n;
	return (n_abs);
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

char				*signed_dec_to_str(long long n, char size)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
	n_abs = get_n_abs(n, size);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
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

/*
** `get_hexa_letter` gives the letter which corresponds to the base-10 value.
** The parameter `maj` tells whether the letter should in capital or not.
** For example: 9 -> 9  |  10 -> a  |  15 -> f
*/

char				get_hexa_letter(int hex_modulo, char maj)
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

char				*unsigned_to_str(t_ull n, char base, char size, char cap)
{
	char				*number;
	int					len;

	(size == 0) ? n = (unsigned int)n : 0;
	(size == 1) ? n = (unsigned char)n : 0;
	(size == 2) ? n = (unsigned short)n : 0;
	(size == 3) ? n = (unsigned long)n : 0;
	(size == 4) ? n = (unsigned long long)n : 0;
	len = get_unsigned_base_len(n, base);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
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



// sandbox for floats
// size `l`: double (ignored, because by default, it's a double)
// size `L`: long double

// handle integer and decimal parts separatly
// Integer part can then be handled as normal int (explicit cast into a t_ull, then itoa)
//   Actually, not possible because the integer part of a long double can be
//   larger than LONG_LONG_MAX...
//   => do we get numbers larger than that?
// Decimal part should be multiplied by 10 as many times as the precision asks

#include <stdio.h>

int					get_double_len(long double f)
{
	int					len;

	len = 1;
	while (f > 10)
	{
		len++;
		f /= 10;
	}
	return (len);
}

char				*handle_int_part(long double f)
{
	char				*number;
	int					len;

	len = (f < 0) ? get_double_len(f) + 1 : get_double_len(f);
	printf("len: %d\n", len);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	if (f < 0)
		number[0] = '-';
	if (f == 0)
		number[0] = '0';
	while (f > 10)
	{
		number[len--] = (f % 10) + 48;
		f /= 10;
	}
	number[len--] = (f % 10) + 48;
	f /= 10;
	return (number);
}

int				main(void)
{
	double f = 33.14;
	printf("%f\n", f);

	printf("len: %d\n", get_double_len(f));
	
	// printf("Storage size for float : %lu\n", sizeof(float));
	// printf("Minimum float positive value: %f\n", FLT_MIN );
	// printf("Maximum float positive value: %f\n", FLT_MAX );
	// printf("Precision value: %d\n", FLT_DIG );

	return (0);
}
