/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:16:08 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 12:37:31 by yustinov         ###   ########.fr       */
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

	if (ft_chrinstr(c->specifier) == 0)
		return (-1);
	len = -1;
	if (c->specifier == 'c')
		len = ft_handle_char(c, va_arg(ap, char));
	if (c->specifier == 's')
		len = ft_handle_str(c, va_arg(ap, char *));
	if (c->specifier == 'x' || c->specifier == 'X')
		len = ft_handle_hex(c, va_arg(ap, int));
	if (c->specifier == 'p')
		len = ft_handle_addr(c, va_arg(ap, void *));
	if (c->specifier == 'i' || c->specifier == 'd')
		len = ft_handle_int(c, va_arg(ap, int));
	if (c->specifier == 'u')
		len = ft_handle_uint(c, va_arg(ap, unsigned int));
	if (c->specifier == '%')
		len = write (STDOUT_FILENO, "%", 1);
	return (len);
}
