/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:22:21 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 13:40:27 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	proc_l(unsigned int i, int l, int w);
static void	proc_r(t_Config *c, unsigned int i, int l, int w);

int	ft_handle_uint(t_Config *config, va_list ap)
{
	unsigned long	uint;
	int				ilen;
	int				width;

	uint = (unsigned long)va_arg(ap, unsigned int);
	ilen = ft_uilen(uint);
	if (config->precision != -1
		&& config->precision > ilen)
		ilen = config->precision;
	if (uint == 0)
		ilen++;
	width = config->width - ilen;
	if (width < 0)
		width = 0;
	if (config->left_justify == 1)
		proc_l(uint, ilen, width);
	if (config->left_justify == 0)
		proc_r(config, uint, ilen, width);
	return (ilen + width);
}

static void	proc_l(unsigned int i, int l, int w)
{
	ft_putui(i, l);
	ft_filln_with(w, ' ');
	return ;
}

static void	proc_r(t_Config *c, unsigned int i, int l, int w)
{
	if (c->pad_zero == 1)
		ft_filln_with(w, '0');
	else
		ft_filln_with(w, ' ');
	ft_putui(i, l);
	return ;
}
