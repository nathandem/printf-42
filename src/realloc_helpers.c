/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:05:02 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/12 18:31:31 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** `realloc_with_add_on_left` reallocates the string `str` with the string
** `left_str` appended to it. It also frees its pointer, so that it's possible
** to call the function and store its result with the same pointer `str`.
** Note: `left_str` is not freed, you need to free it yourself once you're done
** with it.
*/

char		*realloc_with_add_on_left(char *str, char *left_str)
{
	char		*ns;

	if (!str || !left_str)
		return (NULL);
	if (!(ns = ft_strnew(ft_strlen(str) + ft_strlen(left_str))))
		return (NULL);
	ft_strcpy(ns, left_str);
	ft_strcat(ns, str);
	free(str);
	return (ns);
}

/*
** `realloc_with_add_on_right` works the same than `realloc_with_add_on_left`
** except that instead of adding a string on the left, it adds it on the right.
*/

char		*realloc_with_add_on_right(char *str, char *right_str)
{
	char		*ns;

	if (!str || !right_str)
		return (NULL);
	if (!(ns = ft_strnew(ft_strlen(str) + ft_strlen(right_str))))
		return (NULL);
	ft_strcpy(ns, str);
	ft_strcat(ns, right_str);
	free(str);
	return (ns);
}

/*
** `ft_strnjoin` concatenates an arbitrary `nb_args` amount of string arguments
** into one single string.
** Note: the merged strings don't freed. Free them yourself is if needed.
*/

// assume stdarg.h is included in the header file of the lib
char		*ft_strnjoin(int nb_args, ...)
{
	va_list		ap;
	int			i;
	char		*str;
	char		*right;

	if (!(str = (char*)malloc(1)))
		return (NULL);
	str[0] = 0;
	va_start(ap, nb_args);
	i = -1;
	while (++i < nb_args)
	{
		printf("str: %s (loop %d)\n", str, i);
		right = va_arg(ap, char*);
		str = realloc_with_add_on_right(str, right);
	}
	va_end(ap);
	return (str);
}

