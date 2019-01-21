/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:47:38 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/22 14:21:15 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

/*
** `get_int_len` mesures the length of an int by iteratively chopping its
** units until the int is worth 0.
*/

int				get_decimal_len(long long n)
{
	int				len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

/*
** `int_to_str` converts an int into a string (i.e. an array of chars).
** Edge cases covered here: `0`, asymmetry between min/max for signed int.
*/

// I feel like `int_to_str` can also handle hh (signed char), h (signed short),
// l (signed long) and ll (signed long long).
// Yet, may have to use signed long long as param and unsigned long long
// to hold the absolute value.
// Add this explanation to the docstring.

char				*decimal_to_str(long long n)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;

	len = (n < 0) ? get_decimal_len(n) + 1 : get_decimal_len(n);
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

int				get_octal_len(long long n)
{
	int				len;

	len = 1;
	while (n /= 8)
		len++;
	return (len);
}

/*
** `octal_to_str` converts an octal-based number stored in an integer variant
** (i.e. from a signed/unsigned char to a signed/unsigned long long) into a
** string (i.e. an array of ASCII-encoded chars).
*/

// factorization with decimal_to_str may be possible

char				*octal_to_str(long long n)
{
	char				*number;
	int					len;
	unsigned long long	n_abs;

	len = (n < 0) ? get_octal_len(n) + 1 : get_octal_len(n);
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
