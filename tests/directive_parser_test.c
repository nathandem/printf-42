/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directive_parser_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:33:52 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/20 18:56:14 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				display_t_dir(t_dir *cur_dir);

/*
** Any idea of more complex tests?
*/

int					main(void)
{
	// type tests
	/*
	display_t_dir(parse_dir("%c"));
	display_t_dir(parse_dir("%s"));
	display_t_dir(parse_dir("%p"));
	display_t_dir(parse_dir("%i"));
	display_t_dir(parse_dir("%X"));
	display_t_dir(parse_dir("%a"));
	display_t_dir(parse_dir("%O"));
	*/
	// => above tests suggest type parsing works fine

	// optional flags tests
	/*
	display_t_dir(parse_dir("%#0- +d"));
	display_t_dir(parse_dir("%##00--  ++d"));
	display_t_dir(parse_dir("%#0- +"));  // invalid one
	display_t_dir(parse_dir("%#0- 8dfe+"));
	*/
	// => above tests suggest flags parsing is okay

	// optional minimum width field
	/*
	display_t_dir(parse_dir("%5d"));
	display_t_dir(parse_dir("%5.19d"));
	display_t_dir(parse_dir("%5 .19p")); // invalid
	*/
	// => above tests suggest min width field is good

	// optional precision
	/*
	display_t_dir(parse_dir("%.7i"));
	display_t_dir(parse_dir("%.0i"));
	display_t_dir(parse_dir("%.i"));
	display_t_dir(parse_dir("%05.7i"));
	display_t_dir(parse_dir("%0# 5.7i"));
	*/
	// => above tests suggest precision is handled correctly

	// optional size
	/*
	display_t_dir(parse_dir("%hd")); // 1
	display_t_dir(parse_dir("%hhi")); // 2
	display_t_dir(parse_dir("%lu")); // 3
	display_t_dir(parse_dir("%llo")); // 4
	display_t_dir(parse_dir("%Lf")); // 5
	display_t_dir(parse_dir("%hhhf"));
	display_t_dir(parse_dir("%hh"));
	*/
	// => above tests suggest size is good
	
	// complex tests
	display_t_dir(parse_dir("%-15s"));
	display_t_dir(parse_dir("%sc\n"));
	display_t_dir(parse_dir("flag ll :%lld:\n")); // invalid
	display_t_dir(parse_dir("%lld:\n")); // invalid
	display_t_dir(parse_dir("")); // invalid
	display_t_dir(parse_dir("%##X\n"));
	display_t_dir(parse_dir("%+"));
	display_t_dir(parse_dir("%.*f")); // should I handle `*`?
	display_t_dir(parse_dir("%#+ ++ ## 05.3d"));
	// => above tests behaves as I think they should

	return (0);
}
