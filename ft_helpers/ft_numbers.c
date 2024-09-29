/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:23:57 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 12:51:54 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 * Simple numlen function
 * that calculates number
 * of digits in the   int
 */
int	ft_numlen(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_uilen(unsigned long uint)
{
	int	len;

	len = 0;
	while (uint > 0)
	{
		uint = uint / 10;
		len++;
	}
	return (len);
}
