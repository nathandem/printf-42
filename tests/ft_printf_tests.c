#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	// printf("%d\n", printf(":%d:", 1));
	printf("%d\n", ft_printf(":%d:", 1));

	return (0);
}
