/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:19:11 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/28 14:54:50 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void put_hex(unsigned long nbr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		put_hex(nbr / 16);
	write (STDOUT_FILENO, &hex[nbr % 16], 1);
	return ;
	}

int main(void)
{
	unsigned int	ui = 999;
	/*ft_printf("Hello, from custom printf!\n");
	ft_printf("Trying to print out char 'c':%.cabc\n", 'c');
	ft_printf("Trying to print out a string 'Hello': %s\n", "Hello");
	ft_printf("Testing compile time protections", 1, 2);
	ft_printf("Trying to print i, d types:% 0*d;\n", 4, 42);*/
	void	*ptr = &ui;
	unsigned long	addr = (unsigned long)ptr;
	ft_printf("Custom:%06x\n", 16);
	printf("Real  :%06x\n", 16);
}
