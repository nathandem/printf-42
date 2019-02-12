#include <stdio.h>
#include "ft_printf.h"

int				main(void)
{
	printf("ret: %d\n", ft_printf("Hello %d!", 4222));

	return (0);
}
