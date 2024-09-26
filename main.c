/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:19:11 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 14:37:31 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int main(void)
{
	ft_printf("Hello, from custom printf!\n");
	ft_printf("Trying to print out char 'c':  %c\n", 'c');
	ft_printf("Trying to print out a string 'Hello': %s\n", "Hello");
	/*ft_printf("Testing compile time protections", 1, 2); Detecting*/
	ft_printf("Trying to print i, d types: %d", 42);
}
