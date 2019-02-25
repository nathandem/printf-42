/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive_parsers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:05:42 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 11:20:29 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parse_flags(const char *str, t_dir *cur_dir, int *i)
{
	while (str[*i] == '#' || str[*i] == '0' || str[*i] == '-'
			|| str[*i] == ' ' || str[*i] == '+')
	{
		if (str[*i] == '#')
			cur_dir->hash = 1;
		else if (str[*i] == '0')
			cur_dir->zero = 1;
		else if (str[*i] == '-')
			cur_dir->neg_sign = 1;
		else if (str[*i] == ' ')
			cur_dir->space = 1;
		else if (str[*i] == '+')
			cur_dir->pos_sign = 1;
		(*i)++;
	}
}

void				parse_width(const char *str, t_dir *cur_dir, int *i)
{
	if (ft_isdigit(str[*i]))
	{
		cur_dir->width = ABS(ft_atoi(str + *i));
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

void				parse_precision(const char *str, t_dir *cur_dir, int *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		cur_dir->precision = ABS(ft_atoi(str + *i));
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

void				parse_size(const char *str, t_dir *cur_dir, int *i)
{
	if (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'L')
	{
		if (str[*i] == 'h')
		{
			if (str[(*i)++ + 1] == 'h')
				cur_dir->size = hh;
			else
				cur_dir->size = h;
		}
		else if (str[*i] == 'l')
		{
			if (str[(*i)++ + 1] == 'l')
				cur_dir->size = ll;
			else
				cur_dir->size = l;
		}
		else if (str[(*i)++] == 'L')
			cur_dir->size = L;
		(str[(*i)] == 'l' | str[(*i)] == 'h') ? (*i)++ : 0;
	}
}

void				parse_conversion(const char *str, t_dir *cur_dir, int *i)
{
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd' ||
		str[*i] == 'i' || str[*i] == 'o' || str[*i] == 'u' || str[*i] == 'x' ||
		str[*i] == 'X' || str[*i] == 'f' || str[*i] == '%')
	{
		cur_dir->type = str[*i];
		(*i)++;
	}
}
