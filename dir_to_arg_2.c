/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_to_arg_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 08:44:53 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 10:26:16 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (handle_unsigned_integer((t_uc)va_arg(*ap, t_ui), cur_dir));
}

char			*unsigned_short_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_us)va_arg(*ap, t_ui), cur_dir));
}

char			*unsigned_int_dir_to_str(va_list *ap, t_dir *cur_dir)
{
	return (handle_unsigned_integer((t_ui)va_arg(*ap, t_ui), cur_dir));
}
