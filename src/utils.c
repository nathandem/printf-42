/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:29:27 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/12 12:20:33 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

char			*create_str_of_len_char(char c, int len)
{
	char			*str;

	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = 0;
	while (len--)
		str[len] = c;
	return (str);
}
