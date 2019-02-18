#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	// printf("%d\n", ft_printf("%5%"));
	
	printf(":%.10d:\n", -42);
	ft_printf(":%.10d:\n", -42);

	return (0);
}
