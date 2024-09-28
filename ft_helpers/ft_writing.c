/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:30 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/28 15:17:18 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
 * Widly used function, I defined its
 * behavior via interface pattern  so
 * now I simply call whenever I need.
 * It just fill the field 	   of
 * convertion type with chr if  there
 * still present unfilled field bytes
*/
void	ft_filln_with(int fieldsize, char chr)
{
	while (fieldsize > 0)
	{
		write(STDOUT_FILENO, &chr, 1);
		fieldsize--;
	}
	return ;
}

/*
 * Simple recursive putnbr but with minor
 * difference. It also includes the   len
 * of the int, it is helpful when dealing
 * with precision in the printf.Meanwhile
 * the aproach is the same,     recursive
 * calls before printing while number > 0
*/
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

/*
 * Put sign is helpful function to print signs
 * because we will be dealing with other types
 * of numbers. It looks into convertion   type
 * config and outputs sign depending on  flags
 * and number positivity as well.
*/
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

void	ft_putui(unsigned int uint, int length)
{
	char	c;

	if (uint == 0 && length == 0)
		return ;
	if (uint == 0 && length > 0)
	{
		while (length-- > 0)
			write (STDOUT_FILENO, "0", 1);
		return ;
	}
	else
	{
		ft_putui(uint / 10, --length);
		c = uint % 10 + '0';
		write (STDOUT_FILENO, &c, 1);
	}
}
