/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:38:56 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/24 15:23:54 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* Given a mandatory variable char * and va_list;
 * First I initialize va_list and tell it that string is
 * mandatory and other vars are optional;
 * Then I should go through the string and encounter a %;
 * If so I give flow control to next function;
 * Otherwise I write char to a console and  repeat;
 * Return values [-1: ERROR, int: OK (len of chars printed)]
 * Passing addr of pointer to correctly increment position.*/
int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, string);
	if (string == NULL)
		return (-1);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			string++;
			len += ft_parse_convertion(&string, ap);
		}
		else
			len += write(STDOUT_FILENO, &(*string), 1);
		string++;
	}
	va_end(ap);
	return (len);
}
