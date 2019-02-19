#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	// printf("%d\n", ft_printf("%5%"));
	
	printf("%d\n", printf(":%c:", 0));
	printf("%d\n", ft_printf(":%c:", 0));

	return (0);
}
