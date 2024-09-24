/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:22:32 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/24 13:02:42 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_output_cases(const char *format, va_list ap)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		len += ft_print_string(va_arg(ap, char *));
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == '\0')
		return (-1);
	else
		len += write (STDOUT_FILENO, &(*format), 1);
	return (len);
}
