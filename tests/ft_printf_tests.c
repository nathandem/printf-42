#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	// print last char of invalid directive, here `J`
	// printf("%d\n", printf(":foo %00-J %d:", 'c', 12));
	// printf("%d\n", ft_printf(":foo %00-J %d:", 'c', 12));
	
	printf("%d\n", printf(":%lc:", 0x40501));
	printf("%d\n", ft_printf(":%lc:", 0x40501));

	return (0);
}
