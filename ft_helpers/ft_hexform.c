/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexform.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:07:28 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 12:13:17 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static const char	*g_hex = "0123456789abcdef";
static const char	*g_bighex = "0123456789ABCDEF";

void	ft_puthexn(unsigned long address, int length)
{
	if (address <= 0 && length > 0)
	{
		ft_filln_with(length, '0');
		return ;
	}
	if (address >= 16)
		ft_puthexn(address / 16, length - 1);
	write (STDOUT_FILENO, &g_hex[address % 16], 1);
	return ;
}

int	ft_hexlen(unsigned long address)
{
	int	length;

	length = 0;
	while (address != 0)
	{
		address /= 16;
		length++;
	}
	if (length == 0)
		return (1);
	return (length);
}

void	ft_putbighexn(unsigned long address, int length)
{
	if (address <= 0 && length > 0)
	{
		ft_filln_with(length, '0');
		return ;
	}
	if (address >= 16)
		ft_putbighexn(address / 16, length - 1);
	write (STDOUT_FILENO, &g_bighex[address % 16], 1);
	return ;
}
