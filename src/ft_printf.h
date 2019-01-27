/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:35:29 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/22 20:11:25 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** The type `t_dir` is meant to contain the result of a parser directive.
** Considering that a directive has the following form:
** %[flags][width][.precision][size]type
**
** Description of the structure:
** `hash` refers to one of the flags, either 0 if none or 1 if present
** `zero` is a flag, either 0 or 1
** `neg_sign` is a flag, possible value: 0 or 1
** `pos_sign` is a flag, possible value: 0 or 1
** `space` is a flag, possible value: 0 or 1
** `min_width` refers to the min width the res that have, possible value: >=0
** `precision` refers to precision, possible value: >=0
** `size` refers to the conversion of types, possible values:
**		0: `hh` (char, 1 byte)
** 		1: `h` (short, 2 bytes)
**		2: `l` (long, 4 bytes)
**		3: `ll` (long long, 8 bytes)
**		4: `L` (long double, 12 bytes)
** `type` refers to conversion flag, always a char.
**        e.g. `s` for strings, `o` for octals, ...
**	      '.' means the directive is invalid
**
** `len` is a bit special compared to the other variables of the structure
** because it doesn't belong to the directive form, it's rather the length of
** of the directive in the string, the number of characters it takes.
*/

enum			e_size
{
	hh, h, l, ll, L
};

typedef struct	s_directive
{
	int				hash;
	int				zero;
	int				neg_sign;
	int				pos_sign;
	int				space;
	int				min_width;
	int				precision;
	enum e_size		size;
	char			type;
	int				len;
}				t_dir;



// prototypes

void			ft_printf(const char *str, ...);

t_dir			*initialize_a_dir(void);
t_dir			*parse_dir(const char *str);

#endif
