/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:47:38 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/22 20:41:24 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

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
** i.e. `hh` for char (1 byte), `h` for short (2 bytes), `l` for long (4 bytes)
** and `ll` for long long (8 bytes), the function uses the largest of them,
** the `long long`.
** Note: to comply with the function signature, smaller types should be cast
** in `long long` prior.
** This applies to `octal_to_str` and `hex_to_str` as well.
*/

char				*decimal_to_str(long long n)
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

// MAKE THIS WORK WELL (FOR SIGNED VALUES PASSED AND ALL SIZES)
// THEN ADAPT TO OTHERS

char				*unsigned_decimal_to_str(unsigned long long n, int size)
{
	char				*number;
	int					len;

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
