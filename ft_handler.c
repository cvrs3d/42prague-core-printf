/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:16:08 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 17:16:16 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* Arguments: config (already checked in parser so 
 * no pointer check required I guess;
 * va_list to pick out args with va_arg);
 * Return values: returns len of chars printed or -1 if
 * ERROR;*/
int	ft_handler(t_Config *c, va_list ap)
{
	int	len;

	len = -1;
	if (c->specifier == 'c')
		len = ft_handle_char(c, ap);
	if (c->specifier == 's')
		len = ft_handle_str(c, ap);
	if (c->specifier == 'x' || c->specifier == 'X')
		len = ft_handle_hex(c, ap);
	if (c->specifier == 'p')
		len = ft_handle_addr(c, ap);
	if (c->specifier == 'i' || c->specifier == 'd')
		len = ft_handle_int(c, ap);
	if (c->specifier == 'u')
		len = ft_handle_uint(c, ap);
	if (c->specifier == '%')
		len = write (STDOUT_FILENO, "%", 1);
	return (len);
}
