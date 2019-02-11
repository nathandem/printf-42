#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/*
** A `NULL` pointer is passed on the last argument, to tell the stdarg
** when to stop. Loop till reaching NULL.
** All args assumed to be of type `char*`.
*/

void		grocery(char *arg0, ...)
{
	va_list		ap;
	int			i;
	int			nb_args;
	char 		*cur_arg;

	cur_arg = arg0;
	if (arg0 == NULL)
		return ;
	
	va_start(ap, arg0);
	for (
		nb_args = 0;
		cur_arg != NULL;
		printf("cur_arg: %s\n", cur_arg), ++nb_args, cur_arg = va_arg(ap, char*)
	);

	va_end(ap);

	printf("%d stuff to buy\n", nb_args);

	printf("%s", arg0);
	va_start(ap, arg0);
	for (i = 1; i < nb_args; i++) {
		if (i == nb_args - 1)
			printf(" and ");
		else
			printf(", ");
		printf("%s", va_arg(ap, char*));
	}
	printf("\n");

	va_end(ap);
}

/*
** First param used to tell nb of arg the function is passed.
** All args assumed to be of type int.
*/

int			sum(int nb_args, ...)
{
	int			sum;
	int			i;
	va_list		ap;

	sum = 0;
	va_start(ap, nb_args);
	for (i = 0; i < nb_args; i++) {
		int n = va_arg(ap, "int");
		sum += n;
	}
	va_end(ap);
	return (sum);
}

int			main(void)
{
	grocery(NULL);
	grocery("eggs", NULL);
	grocery("eggs", "chocolate", NULL);

	printf("Sum: %d\n", sum(3, 1, 2, 3));

	return (0);
}
