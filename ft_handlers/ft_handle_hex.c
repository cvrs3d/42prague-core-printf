/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:21:23 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/28 15:12:52 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	p_l(t_Config *c, int l, int w, unsigned long h);
static void	p_r(t_Config *c, int l, int w, unsigned long h);

int	ft_handle_hex(t_Config *config, va_list ap)
{
	unsigned long	hex;
	int				length;
	int				width;

	hex = (unsigned long)va_arg(ap, unsigned int);
	length = ft_hexlen(hex);
	if (config->precision > length)
		length = config->precision;
	width = config->width - length;
	if (config->hex_form == 1)
		width -= 2;
	if (width < 0)
		width = 0;
	if (config->left_justify == 1)
		p_l(config, length, width, hex);
	else
		p_r(config, length, width, hex);
	if (config->hex_form == 1)
		length += 2;
	return (length + width);
}

static void	p_l(t_Config *c, int l, int w, unsigned long h)
{
	if (c->hex_form == 1 && l > 1)
		write (STDOUT_FILENO, "0x", 2);
	ft_puthexn(h, l);
	ft_filln_with(w, ' ');
	return ;
}

static void	p_r(t_Config *c, int l, int w, unsigned long h)
{
	if (c->pad_zero == 1)
	{
		if (c->hex_form == 1 && l > 1)
			write (STDOUT_FILENO, "0x", 2);
		ft_filln_with(w, '0');
	}
	else
	{
		ft_filln_with(w, ' ');
		if (c->hex_form == 1 && l > 1)
			write (STDOUT_FILENO, "0x", 2);
	}
	ft_puthexn(h, l);
	return ;
}
