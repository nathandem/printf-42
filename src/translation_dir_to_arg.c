/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_dir_to_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:20:43 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/11 19:53:18 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*char_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_char((char)va_arg(*ap, char), cur_dir));
}

char			*str_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_string((char*)va_arg(*ap, char*), cur_dir));
}

char			*address_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_integer((t_ul)va_arg(*ap, unsigned long), cur_dir));
}

char			*signed_char_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_integer((char)va_arg(*ap, char), cur_dir));
}

char			*signed_short_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_integer((short)va_arg(*ap, short), cur_dir));
}

char			*signed_int_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_integer((int)va_arg(*ap, int), cur_dir));
}

char			*signed_long_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_integer((long)va_arg(*ap, long), cur_dir));
}

char			*signed_long_long_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_integer((t_ull)va_arg(*ap, long long), cur_dir));
}
