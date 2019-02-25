/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_to_arg_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:20:43 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 08:45:45 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (handle_signed_integer((char)va_arg(*ap, int), cur_dir));
}

char			*signed_short_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((short)va_arg(*ap, int), cur_dir));
}

char			*signed_int_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_signed_integer((int)va_arg(*ap, int), cur_dir));
}
