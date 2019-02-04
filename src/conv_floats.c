/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:50:30 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/04 09:50:57 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sandbox for floats
// size `l`: double (ignored, because by default, it's a double)
// size `L`: long double

// handle integer and decimal parts separatly
// Integer part can then be handled as normal int (explicit cast into a t_ull, then itoa)
//   Actually, not possible because the integer part of a long double can be
//   larger than LONG_LONG_MAX...
// Decimal part should be multiplied by 10 as many times as the precision asks

#include <stdio.h>

int					get_double_int_len(long double f)
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

// if the trick of the cast doesn't work, cast the float (double or
// long double) into a long long, then have it handle/transform into a string
// by itoa
// say it's okay for now, for the integer part
char				*handle_int_part(long double f)
{
	char				*number;
	int					len;

	len = (f < 0) ? get_double_int_len(f) + 1 : get_double_int_len(f);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	if (f < 0)
		number[0] = '-';
	if (f == 0)
		number[0] = '0';
	while (f > 10)
	{
		number[len--] = ((long long)f % 10) + 48;
		f /= 10;
	}
	number[len--] = ((long long)f % 10) + 48;
	f /= 10;
	return (number);
}

// don't call this function if precision is 0
char				*handle_dec_part(long double f, int precision)
{
	char				*number;
	int					pos;
	
	pos = 0;
	if (!(number = (char*)malloc(precision + 1)))
		exit(1);
	number[precision] = 0;
	while (precision)
	{
		printf("f: %Lf\n", f);
		f *= 10;
		number[pos++] = ((int)f % 10) + 48;
		precision--;
	}
	return (number);
}

int				main(void)
{
	long double f = (long double)310323882.14; // show it with a precision of 2
	long long whole = (long long)f;
	long double dec = f - whole;

	/*
	printf("%Lf\n", f);
	printf("int part handled by a itoa variant: %s\n", signed_dec_to_str(whole, 4));
	printf("int part: %s\n", handle_int_part(f));
	*/
	printf("decimal part by printf: %Lf\n", dec);
	printf("decimal part: %s\n", handle_dec_part(dec, 4));

	// printf("Storage size for float : %lu\n", sizeof(float));
	// printf("Minimum float positive value: %f\n", FLT_MIN );
	// printf("Precision value: %d\n", FLT_DIG );

	return (0);
}
