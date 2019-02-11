#include <stdio.h>
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%c: hello %s, it's %d A.M.! %hhd\n", 'n', "Lin", 10, 255);
	printf("%hhd\n", 255);

	return (0);
}
