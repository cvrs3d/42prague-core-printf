/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:35:23 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/28 15:38:25 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/* Config type struct contains fields to
 *represent following          config of
 *conversion specifier (%d, %s, %c) left
 *_justify - values: 1 for left 0    for 
 *right; width - minimal field with    0
 * default if > 0 then add      trailing
 * spaces; pad_zero - deafult: 0 if    1
 * then add leading zeroes;  precision - 
 * default: -1 if not used, if 0   print 
 * blank;  hex_form - stands for # flag,
 * default: 0(not used) if 1        adds
 * leading 0x for %p, %x, %X; force_sign
 * - default: 0 if 1 print '+'    before
 * positive (%i, %d); space - default: 0
 * , if 1 prints ' ' before    positive;
 * specifier - represent      convertion 
 * specifier (d, s, c ...) as char    in
 * ascii 't' for default;*/
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

t_Config	*initialize_config(void);
int			ft_printf(const char *s, ...) __attribute__((format(printf, 1, 2)));
int			ft_handle_char(t_Config *config, va_list ap);
int			ft_parse_convertion(const char **format, va_list ap);
int			ft_handler(t_Config *c, va_list ap);
int			ft_handle_str(t_Config *config, va_list ap);
int			ft_handle_int(t_Config *config, va_list ap);
int			ft_handle_uint(t_Config *config, va_list ap);
int			ft_handle_addr(t_Config *config, va_list ap);
int			ft_handle_hex(t_Config *config, va_list ap);
int			ft_strlen(const char *string);
int			ft_numlen(int number);
int			ft_is_alpha(int chr);
int			ft_isdigit(int chr);
int			ft_uilen(unsigned int uint);
int			ft_hexlen(unsigned long addr);
void		ft_putbighexn(unsigned long addr, int length);
void		ft_puthexn(unsigned long addr, int length);
void		ft_putui(unsigned int uint, int length);
void		ft_filln_with(int fieldsize, char chr);
void		ft_putn_nbr(long number, int length);
void		ft_put_sign(t_Config *config, int number);
#endif
