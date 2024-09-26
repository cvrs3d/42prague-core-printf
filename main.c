/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:19:11 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 16:12:57 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("Hello, from custom printf!\n");
	ft_printf("Trying to print out char 'c':%.cabc\n", 'c');
	ft_printf("Trying to print out a string 'Hello': %s\n", "Hello");
	/*ft_printf("Testing compile time protections", 1, 2); Detecting*/
	ft_printf("Trying to print i, d types:% 04d;\n", 42);
	printf("real print ;% 04d;", 42);
}
