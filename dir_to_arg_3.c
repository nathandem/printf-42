/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_to_arg_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 08:45:28 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 10:26:24 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
