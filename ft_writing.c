/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:30 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 13:20:49 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_filln_with(int fieldsize, char chr)
{
	while (fieldsize > 0)
	{
		write(STDOUT_FILENO, &chr, 1);
		fieldsize--;
	}
	return ;
}

void	ft_putn_nbr(long number, int length)
{
	char	c;

	if (number == 0 && length == 0)
		return ;
	if (number == 0 && length > 0)
	{
		while (length-- > 0)
			write (STDOUT_FILENO, "0", 1);
		return ;
	}
	else
	{
		ft_putn_nbr(number / 10, --length);
		c = number % 10 + '0';
		write (STDOUT_FILENO, &c, 1);
	}
}

void	ft_put_sign(t_Config *config, int number)
{
	if (number < 0)
	{
		write (STDOUT_FILENO, "-", 1);
		return ;
	}
	if (config->force_sign == 1 && number > 0)
	{
		write (STDOUT_FILENO, "+", 1);
		return ;
	}
	return ;
}
