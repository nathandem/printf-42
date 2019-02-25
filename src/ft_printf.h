/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:35:29 by nde-maes          #+#    #+#             */
/*   Updated: 2019/02/25 12:27:46 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define ABS(Value) (((Value) >= 0) ? (Value) : (-Value))

typedef unsigned char		t_uc;
typedef unsigned short		t_us;
typedef unsigned int		t_ui;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

enum			e_size
{
	NONE, hh, h, l, ll, L
};

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
** `width` refers to the min width the res that have, possible value: >=0
** `precision` refers to precision, possible value: >=0
** `size` refers to the conversion of types, possible values:
**		0: `hh` (char, 1 byte)
** 		1: `h` (short, 2 bytes)
**		2: `l` (long, 8 bytes) Note: on some architectures, it's 4 bytes only
**		3: `ll` (long long, 8 bytes)
**		4: `L` (long double, 12 bytes)
** `type` refers to conversion flag, always a char.
**        e.g. `s` for strings, `o` for octals, ...
**	      '.' means the directive is invalid
** `len` is a bit special compared to the other variables of the structure
** because it doesn't belong to the directive form, it's rather the length of
** of the directive in the string, the number of characters it takes.
*/

typedef struct	s_directive
{
	int				hash;
	int				zero;
	int				neg_sign;
	int				pos_sign;
	int				space;
	int				width;
	int				precision;
	enum e_size		size;
	char			type;
	int				len;
}				t_dir;

typedef struct	s_d2h
{
	char			type;
	enum e_size		size;
	char			*(*ft_d2h)(va_list*, t_dir*);
}				t_d2h;

/*
** Entry point of the project.
*/

int				ft_printf(const char *str, ...);

/*
** Parsing functions used to extract the meaning of directives into the
** t_dir type declared above.
*/

t_dir			*parse_dir(const char *str);
t_dir			*initialize_a_dir(void);
void			parse_flags(const char *str, t_dir *cur_dir, int *i);
void			parse_width(const char *str, t_dir *cur_dir, int *i);
void			parse_precision(const char *str, t_dir *cur_dir, int *i);
void			parse_size(const char *str, t_dir *cur_dir, int *i);
void			parse_conversion(const char *str, t_dir *cur_dir, int *i);
void			clean_dir_from_unsupported_flags(t_dir *cur_dir);

/*
** Handler functions. Are meant to take a value (e.g. char, int, ...) and
** and a formating directive (i.e. an instance of t_dir) and print on stdout
** the formated result of the operation.
*/

char			*handle_char(char c, t_dir *cur_dir);
char			*handle_string(char *str, t_dir *cur_dir);
char			*handle_signed_integer(long long n, t_dir *cur_dir);
char			*handle_unsigned_integer(unsigned long long n, t_dir *cur_dir);
char			*handle_float(double f, t_dir *cur_dir);
char			*handle_pourcent(t_dir *cur_dir);

char			*handle_sign_mark(char *res, t_dir *cur_dir, int n_shape);
char			*handle_hash(char *res, t_dir *cur_dir, int n_shape);
char			*handle_width(char *res, t_dir *cur_dir, int tmp_len);
char			*handle_precision(char *res, t_dir *cur_dir, int n_shape);

char			*signed_dec_to_str(long long n);
char			*unsigned_to_str(t_ull n, int base, int cap);

/*
** The following are just to ensure a mapping between stdargs and
** handler functions.
*/

char			*str_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*address_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*signed_char_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*signed_short_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*signed_int_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*signed_long_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*signed_long_long_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*unsigned_char_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*unsigned_short_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*unsigned_int_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*unsigned_long_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*unsigned_long_long_dir_to_str(va_list *ap, t_dir *cur_dir);
char			*float_dir_to_str(va_list *ap, t_dir *cur_dir);

/*
** Helper functions.
*/

char			*create_str_of_len_char(char c, int len);
char			*realloc_with_add_on_left(char *str, char *left_str);
char			*realloc_with_add_on_right(char *str, char *right_str);
char			*ft_strnjoin(int nb_args, ...);
void			putchar_and_increment_ret(char c, int *ret);

#endif
