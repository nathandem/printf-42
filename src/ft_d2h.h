/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d2h.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:34:27 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/11 19:46:13 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is a disaster of conciseness.
*/

t_d2h			g_d2h[13] =
{
	{'c', NONE, &char_dir_to_str},
	{'s', NONE, &str_dir_to_str},
	{'p', NONE, &address_dir_to_str},

	{'d', h, &signed_char_dir_to_str},
	{'i', h, &signed_char_dir_to_str},
	{'d', hh, &signed_short_dir_to_str},
	{'i', hh, &signed_short_dir_to_str},
	{'d', NONE, &signed_int_dir_to_str},
	{'i', NONE, &signed_int_dir_to_str},
	{'d', l, &signed_long_dir_to_str},
	{'i', l, &signed_long_dir_to_str},
	{'d', ll, &signed_long_long_dir_to_str},
	{'i', ll, &signed_long_long_dir_to_str},
};
