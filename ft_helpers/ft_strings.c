/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:37:38 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 12:13:39 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 * Computes string length, while this
 * is internaly defined function    I
 * do not think that NULL checking is
 * very useful here, because  pointer
 * is checked before so it kind    of
 * safe?...Anyways added.
*/
int	ft_strlen(const char *string)
{
	int	len;

	if (string == NULL)
		return (0);
	len = 0;
	while (*string != '\0')
	{
		string++;
		len++;
	}
	return (len);
}

int	ft_is_alpha(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		return (1);
	if (chr >= 'A' && chr <= 'Z')
		return (1);
	return (0);
}

int	ft_isdigit(int chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	return (0);
}
