#include "ft_printf.h"
#include <stdio.h>

void			handle_integer(long long n, t_dir *cur_dir);

int				main(void)
{
	char			*str;
	t_dir			*cur_dir;

	printf("%u%%\n", 42);

	cur_dir = initialize_a_dir();
	cur_dir->type = 'u';
	handle_integer(42, cur_dir);
	
	return (0);
}
