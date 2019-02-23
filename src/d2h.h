/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2h.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:34:27 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/23 11:50:24 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This is a disaster of conciseness.
*/

t_d2h			g_d2h[35] =
{
	{'s', NONE, &str_dir_to_str},
	{'p', NONE, &address_dir_to_str},

	{'d', hh, &signed_char_dir_to_str},
	{'d', h, &signed_short_dir_to_str},
	{'d', NONE, &signed_int_dir_to_str},
	{'d', l, &signed_long_dir_to_str},
	{'d', ll, &signed_long_long_dir_to_str},

	{'i', hh, &signed_char_dir_to_str},
	{'i', h, &signed_short_dir_to_str},
	{'i', NONE, &signed_int_dir_to_str},
	{'i', l, &signed_long_dir_to_str},
	{'i', ll, &signed_long_long_dir_to_str},

	{'u', hh, &unsigned_char_dir_to_str},
	{'u', h, &unsigned_short_dir_to_str},
	{'u', NONE, &unsigned_int_dir_to_str},
	{'u', l, &unsigned_long_dir_to_str},
	{'u', ll, &unsigned_long_long_dir_to_str},

	{'o', hh, &unsigned_char_dir_to_str},
	{'o', h, &unsigned_short_dir_to_str},
	{'o', NONE, &unsigned_int_dir_to_str},
	{'o', l, &unsigned_long_dir_to_str},
	{'o', ll, &unsigned_long_long_dir_to_str},

	{'x', hh, &unsigned_char_dir_to_str},
	{'x', h, &unsigned_short_dir_to_str},
	{'x', NONE, &unsigned_int_dir_to_str},
	{'x', l, &unsigned_long_dir_to_str},
	{'x', ll, &unsigned_long_long_dir_to_str},

	{'X', hh, &unsigned_char_dir_to_str},
	{'X', h, &unsigned_short_dir_to_str},
	{'X', NONE, &unsigned_int_dir_to_str},
	{'X', l, &unsigned_long_dir_to_str},
	{'X', ll, &unsigned_long_long_dir_to_str},

	{'f', NONE, &float_dir_to_str},
	{'f', l, &float_dir_to_str},
	{'f', L, &float_dir_to_str},
};
