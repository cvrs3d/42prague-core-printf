/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:38:56 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 10:38:43 by yustinov         ###   ########.fr       */
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
 * Passing addr of pointer to correctly increment position.
 * Error handling: if for some unknown reason -1 is returned
 * from any function in chain, -1 is returned.*/
int	ft_printf(const char *string, ...) __attribute__((format(printf, 1, 2)));

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		len;
	int		err;

	len = 0;
	va_start(ap, string);
	if (string == NULL)
		return (-1);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			string++;
			err = ft_parse_convertion(&string, ap);
		}
		else
			err = write(STDOUT_FILENO, &(*string), 1);
		if (err < 0)
			return (-1);
		len += err;
		string++;
	}
	va_end(ap);
	return (len);
}
