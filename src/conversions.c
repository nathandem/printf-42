/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:47:38 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/27 18:50:17 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "ft_printf.h"

/*
** `get_base_len` mesures the length of an int by iteratively chopping its
** units by dividing by its base until the int is worth 0.
*/

int				get_base_len(long long n, int base)
{
	int				len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

/*
** `int_to_str` converts an integer into a string (i.e. an array of
** chars). Edge cases covered here: `0`, asymmetry between min/max for signed
** int. The number is accessed as a base 10 by default.
**
** To allow the function to handle all size flags/all possible inputs safely,
** i.e. `hh` for char (1 byte), `h` for short (2 bytes), `l` for long (8 bytes)
** and `ll` for long long (8 bytes), the function uses the largest of them,
** the `long long`.
** Note: to comply with the function signature, smaller types should be cast
** in `long long` prior.
** This applies to `octal_to_str` and `hex_to_str` as well.
*/

// this one is working well :)
char				*signed_char_decimal_to_str(char n)
{
	char				*number;
	int					len;
	unsigned char		n_abs;

	len = (n < 0) ? get_base_len(n, 10) + 1 : get_base_len(n, 10);
	n_abs = (n < 0) ? (unsigned char)(-n) : (unsigned char)n;
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

// this one works just fine as well :) 
char				*signed_short_decimal_to_str(short n)
{
	char				*number;
	int					len;
	unsigned short		n_abs;

	len = (n < 0) ? get_base_len(n, 10) + 1 : get_base_len(n, 10);
	n_abs = (n < 0) ? (unsigned short)(-n) : (unsigned short)n;
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

// this one is working well :)
char				*signed_int_decimal_to_str(int n)
{
	char				*number;
	int					len;
	unsigned int		n_abs;

	len = (n < 0) ? get_base_len(n, 10) + 1 : get_base_len(n, 10);
	n_abs = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
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

// eventhough it's quite possible that long as the same nb of bytes
// than an int, it's also possible that it's not the case
// So go for 2 functions so that the compiler can choose what values it
// allocates for a long, that way no prob if `long` is longer than `int`
// src:
// https://software.intel.com/en-us/articles/size-of-long-integer-type-on-different-architecture-and-os
// https://developer.apple.com/library/archive/documentation/Darwin/Conceptual/64bitPorting/transition/transition.html
char				*signed_long_decimal_to_str(long n)
{
	char				*number;
	int					len;
	unsigned long		n_abs;

	len = (n < 0) ? get_base_len(n, 10) + 1 : get_base_len(n, 10);
	n_abs = (n < 0) ? (unsigned long)(-n) : (unsigned long)n;
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

// In the case of my architecture (macOS 64bits), `long long` and `long`
// are both 64bits long.
char				*signed_long_long_decimal_to_str(long long n)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;

	len = (n < 0) ? get_base_len(n, 10) + 1 : get_base_len(n, 10);
	n_abs = (n < 0) ? (unsigned long long)(-n) : (unsigned long long)n;
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


// UNSIGNED DECIMALS

char				*unsigned_int_decimal_to_str(unsigned int n)
{
	char				*number;
	int					len;

	len = get_base_len(n, 10);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	(n == 0) ? number[0] = '0' : 0;
	while (n)
	{
		number[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (number);
}

char				*unsigned_long_decimal_to_str(unsigned long n)
{
	char				*number;
	int					len;

	len = get_base_len(n, 10);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	(n == 0) ? number[0] = '0' : 0;
	while (n)
	{
		number[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (number);
}

char				*unsigned_decimals_to_str(unsigned long long n, char size)
{
	char				*number;
	int					len;

	(size == 0) ? n = (unsigned int)n : 0;
	(size == 1) ? n = (unsigned char)n : 0;
	(size == 2) ? n = (unsigned short)n : 0;
	(size == 3) ? n = (unsigned long)n : 0;
	len = get_base_len(n, 10);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	(n == 0) ? number[0] = '0' : 0;
	while (n)
	{
		number[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (number);
}



/*
** `octal_to_str` converts a number stored in an integer variant
** (i.e. from a signed/unsigned char to a signed/unsigned long long) into a
** string (i.e. an array of ASCII-encoded chars).
** Note: eventhough numbers are stored in base 2 in the bits of the interger,
** C provides us with base-10 values. That's why we convert the values from
** base 10 to base 8 here, not from base 2 to base 8.
*/

char				*octal_to_str(long long n)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;

	len = (n < 0) ? get_base_len(n, 8) + 1 : get_base_len(n, 8);
	n_abs = (n < 0) ? (unsigned long long)(-n) : (unsigned long long)n;
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	if (n < 0)
		number[0] = '-';
	if (n == 0)
		number[0] = '0';
	while (n_abs)
	{
		number[len--] = (n_abs % 8) + 48;
		n_abs /= 8;
	}
	return (number);
}



char				*unsigned_octal_to_str(unsigned long long n, int size)
{
	char				*number;
	int					len;

	(size == 1) ? n = (unsigned char)n : 0;
	(size == 2) ? n = (unsigned short)n : 0;
	(size == 3) ? n = (unsigned long)n : 0;
	len = get_base_len(n, 8);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	(n == 0) ? number[0] = '0' : 0;
	while (n)
	{
		number[len--] = (n % 8) + 48;
		n /= 8;
	}
	return (number);
}

/*
** `hex_to_str` works as `octal_to_str` and `decimal_to_str`, except that
** it has a `maj` flag which tells whether or not the letters representing
** the values above 9 to 15 should be capitalize or not.
*/

char				*hex_to_str(long long n, char maj)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;
	unsigned char		character;

	len = (n < 0) ? get_base_len(n, 16) + 1 : get_base_len(n, 16);
	n_abs = (n < 0) ? (unsigned long long)(-n) : (unsigned long long)n;
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	if (n < 0)
		number[0] = '-';
	if (n == 0)
		number[0] = '0';
	while (n_abs)
	{
		character = n_abs % 16;
		if (character < 10)
			character = character + 48;
		else
			character = (maj) ? character + 55 : character + 87;
		number[len--] = character;
		n_abs /= 16;
	}
	return (number);
}
