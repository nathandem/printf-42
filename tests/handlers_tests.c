#include "ft_printf.h"
#include <stdio.h>

void			handle_integer(long long n, t_dir *cur_dir);
void			handle_char(char c, t_dir *cur_dir);

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


	return (0);
}
