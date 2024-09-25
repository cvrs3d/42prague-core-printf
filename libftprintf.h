/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:23 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 12:01:41 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/* Config type struct contains fields to
 *represent following config of conversion
 *specifier (%d, %s, %c)
 * left_justify - values: 1 for left 0 for right;
 * width - minimal field with 0 default if > actual then
 *add trailing spaces;
 * pad_zero - deafult: 0 if > actual then add
 *leading zeroes;
 * precision - default: -1 if not used, if 0
 *print blank;
 * hex_form - stands for # flag, default: 0(not used)
 *if 1 adds leading 0x for %p, %x, %X;
 * force_sign - default: 0 if 1 print '+' before positive (%i, %d);
 * space - default: 0, if 1 prints ' ' before positive;
 * specifier - represent convertion specifier (d, s, c ...) as char in ascii
 * 't' for default;*/
typedef struct t_config
{
	int	left_justify;
	int	width;
	int	pad_zero;
	int	precision;
	int	hex_form;
	int	force_sign;
	int	space;
	int	specifier;
}		t_Config;

int	ft_printf(const char *string, ...) __attribute__((format(printf, 1, 2)));
int	ft_output_cases(const char *format, va_list ap);
int	ft_print_string(const char *string);
int	ft_putchar(int c);
int	ft_parse_convertion(const char **format, va_list ap);
#endif
