/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:45:51 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/24 12:51:19 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_string(const char *string)
{
	const char	*null_str;
	int			len;
	int			ret;

	null_str = "(null)";
	len = 0;
	ret = 0;
	if (string == NULL)
		string = null_str;
	while (*string != '\0')
	{
		ret = write(STDOUT_FILENO, string++, 1);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (ret == -1)
		return (-1);
	len += ret;
	return (len - 1);
}
