/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_dir_to_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:20:43 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/18 10:55:11 by nde-maes         ###   ########.fr       */
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
	return (handle_unsigned_integer((t_ul)va_arg(*ap, t_ul), cur_dir));
}

char			*signed_char_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((char)va_arg(*ap, char), cur_dir));
}

char			*signed_short_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((short)va_arg(*ap, short), cur_dir));
}

char			*signed_int_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((int)va_arg(*ap, int), cur_dir));
}

char			*signed_long_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((long)va_arg(*ap, long), cur_dir));
}

char			*signed_long_long_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((long long)va_arg(*ap, long long), cur_dir));
}

char			*unsigned_char_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_uc)va_arg(*ap, t_uc), cur_dir));
}

char			*unsigned_short_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_us)va_arg(*ap, t_us), cur_dir));
}

char			*unsigned_int_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_ui)va_arg(*ap, t_ui), cur_dir));
}

char			*unsigned_long_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_ul)va_arg(*ap, t_ul), cur_dir));
}

char			*unsigned_long_long_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_ull)va_arg(*ap, t_ull), cur_dir));
}

char			*float_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_float((double)va_arg(*ap, t_ull), cur_dir));
}
