#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	char			*str;
	t_dir			*cur_dir;


	// `p` conversions

	/*
	printf(":%p:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	handle_integer('a', cur_dir);
	*/

	/*
	printf(":%p:\n", 0);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	handle_integer(0, cur_dir);
	*/

	/*
	printf(":%.6p:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	cur_dir->precision = 6;
	handle_integer('a', cur_dir);
	*/

	/*
	printf(":%7.4p:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	cur_dir->precision = 4;
	cur_dir->width = 7;
	handle_integer('a', cur_dir);
	*/

	/*
	printf(":%06p:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	cur_dir->width = 6;
	cur_dir->zero = 1;
	handle_integer('a', cur_dir);
	*/

	/*
	printf(":%-6p:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	cur_dir->width = 6;
	cur_dir->neg_sign = 1;
	handle_integer('a', cur_dir);
	*/


	/*
	printf(":%-06p:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->type = 'p';
	cur_dir->width = 6;
	cur_dir->zero = 1;
	cur_dir->neg_sign = 1;
	handle_integer('a', cur_dir);
	*/




	// numbers conversions

	/*
	printf("%0#8.5x\n", 16);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'x';
	cur_dir->zero = 1;
	cur_dir->hash = 1;
	cur_dir->width = 8;
	cur_dir->precision = 5;
	handle_integer(16, cur_dir);
	*/

	/*
	printf("%0#8x\n", 16);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'x';
	cur_dir->zero = 1;
	cur_dir->hash = 1;
	cur_dir->width = 8;
	handle_integer(16, cur_dir);
	*/

	/*
	printf("%#8.5x\n", 16);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'x';
	cur_dir->hash = 1;
	cur_dir->width = 8;
	cur_dir->precision = 5;
	handle_integer(16, cur_dir);
	*/

	/*
	printf(":%4.3d:\n", 42);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'd';
	cur_dir->width = 4;
	cur_dir->precision = 3;
	handle_integer(42, cur_dir);
	*/

	/*
	printf("%#8.5x\n", 16);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'x';
	cur_dir->precision = 5;
	cur_dir->hash = 1;
	cur_dir->width = 8;
	handle_integer(16, cur_dir);
	*/

	/*
	printf(":%+.d:\n", 0);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'd';
	cur_dir->pos_sign = 1;
	cur_dir->precision = 0;
	handle_integer(0, cur_dir);
	*/

	
	// `c` conversions

	/*
	printf(":%02c:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->zero = 1;
	cur_dir->type = 'c';
	cur_dir->width = 2;
	handle_char('a', cur_dir);
	*/

	/*
	printf(":%0-2c:\n", 'a');
	cur_dir = initialize_a_dir();
	cur_dir->zero = 1;
	cur_dir->neg_sign = 1;
	cur_dir->type = 'c';
	cur_dir->width = 2;
	handle_char('a', cur_dir);
	*/


	// `s` conversions

	/*
	printf(":%s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	handle_string("hello world!", cur_dir);
	*/

	/*
	printf(":%.5s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->precision = 5;
	handle_string("hello world!", cur_dir);
	*/

	/*
	printf(":%.15s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->precision = 15;
	handle_string("hello world!", cur_dir);
	*/

	/*
	// nothing printed
	printf(":%.0s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->precision = 0;
	handle_string("hello world!", cur_dir);
	*/

	/*
	// width < len str (10 < 12)
	printf(":%10s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->width = 10;
	handle_string("hello world!", cur_dir);
	*/

	/*
	// width > len str (15 > 12)
	printf(":%15s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->width = 15;
	handle_string("hello world!", cur_dir);
	*/

	/*
	printf(":%0s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->width = 0;
	handle_string("hello world!", cur_dir);
	*/

	/*
	printf(":%015s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->zero = 1;
	cur_dir->width = 15;
	handle_string("hello world!", cur_dir);
	*/

	/*
	printf(":%-15.5s:\n", "hello world!");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	cur_dir->neg_sign = 1;
	cur_dir->width = 15;
	cur_dir->precision = 5;
	handle_string("hello world!", cur_dir);
	*/

	/*
	printf(":%s:\n", "%s");
	cur_dir = initialize_a_dir();
	cur_dir->type = 's';
	handle_string("%s", cur_dir);
	*/


	// `f` conversions

	char		*tmp;

	/*
	printf(":%7.3f:\n", -3.14);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'f';
	cur_dir->precision = 3;
	cur_dir->width = 7;
	cur_dir->pos_sign = 1;
	tmp = handle_float(-3.14, cur_dir);
	printf(":%s:\n", tmp);
	*/

	printf(":% .3f:\n", 3.14);
	cur_dir = initialize_a_dir();
	cur_dir->type = 'f';
	cur_dir->precision = 3;
	cur_dir->space = 1;
	cur_dir->pos_sign = 1;
	tmp = handle_float(3.14, cur_dir);
	printf(":%s:\n", tmp);


	return (0);
}
