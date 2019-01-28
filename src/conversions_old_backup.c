// backup of working functions in case...

char				*signed_char_decimal_to_str(char n)
{
	char				*number;
	int					len;
	unsigned char		n_abs;

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
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

char				*signed_short_decimal_to_str(short n)
{
	char				*number;
	int					len;
	unsigned short		n_abs;

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
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

char				*signed_int_decimal_to_str(int n)
{
	char				*number;
	int					len;
	unsigned int		n_abs;

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
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

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
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

	len = (n < 0) ? get_signed_base_len(n, 10) + 1 : get_signed_base_len(n, 10);
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

char				*unsigned_decimals_to_str(unsigned long long n, char size)
{
	char				*number;
	int					len;

	(size == 0) ? n = (unsigned int)n : 0;
	(size == 1) ? n = (unsigned char)n : 0;
	(size == 2) ? n = (unsigned short)n : 0;
	(size == 3) ? n = (unsigned long)n : 0;
	(size == 4) ? n = (unsigned long long)n : 0;
	len = get_unsigned_base_len(n, 10);
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

char				*unsigned_octals_to_str(unsigned long long n, char size)
{
	char				*number;
	int					len;

	(size == 0) ? n = (unsigned int)n : 0;
	(size == 1) ? n = (unsigned char)n : 0;
	(size == 2) ? n = (unsigned short)n : 0;
	(size == 3) ? n = (unsigned long)n : 0;
	(size == 4) ? n = (unsigned long long)n : 0;
	len = get_unsigned_base_len(n, 8);
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

char				*uhexas_to_str(unsigned long long n, char size, char maj)
{
	char				*number;
	int					len;

	(size == 0) ? n = (unsigned int)n : 0;
	(size == 1) ? n = (unsigned char)n : 0;
	(size == 2) ? n = (unsigned short)n : 0;
	(size == 3) ? n = (unsigned long)n : 0;
	(size == 4) ? n = (unsigned long long)n : 0;
	len = get_unsigned_base_len(n, 16);
	if (!(number = (char*)malloc(len + 1)))
		exit(1);
	number[len--] = 0;
	(n == 0) ? number[0] = '0' : 0;
	while (n)
	{
		number[len--] = get_hexa_letter(n % 16, maj);
		n /= 16;
	}
	return (number);
}
