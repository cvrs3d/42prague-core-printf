/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:23:12 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 12:11:53 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	p_l(int l, int w, unsigned long a);
static void	p_r(t_Config *c, int l, int w, unsigned long a);
static int	handle_null(t_Config *c);

int	ft_handle_addr(t_Config *config, va_list ap)
{
	void			*ptr;
	int				width;
	int				len;
	unsigned long	addr;

	ptr = va_arg(ap, void *);
	if (ptr == NULL)
		return (handle_null(config));
	addr = (unsigned long)ptr;
	len = ft_hexlen(addr) + 2;
	if (config->precision > len)
		len = config->precision;
	width = config->width - len;
	if (width < 0)
		width = 0;
	if (config->left_justify == 1)
		p_l(len - 2, width, addr);
	else
		p_r(config, len - 2, width, addr);
	return (width + len);
}

static void	p_l(int l, int w, unsigned long a)
{
	write (STDOUT_FILENO, "0x", 2);
	ft_puthexn(a, l);
	ft_filln_with(w, ' ');
}

static void	p_r(t_Config *c, int l, int w, unsigned long a)
{
	if (c->pad_zero == 1)
		ft_filln_with(w, '0');
	else
		ft_filln_with(w, ' ');
	write (STDOUT_FILENO, "0x", 2);
	ft_puthexn(a, l);
}

static int	handle_null(t_Config *config)
{
	if (config->hex_form == 1)
	{
		write (STDOUT_FILENO, "0x0", 3);
		return (3);
	}
	else
	{
		write (STDOUT_FILENO, "(nil)", 5);
		return (5);
	}
}
