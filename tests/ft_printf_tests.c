#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	// print last char of invalid directive, here `J`
	// printf("%d\n", printf(":foo %00-J %d:", 'c', 12));
	// printf("%d\n", ft_printf(":foo %00-J %d:", 'c', 12));
	
	printf("%d\n", printf(":%lx:", 4294967296));
	printf("%d\n", ft_printf(":%lx:", 4294967296));

	return (0);
}
