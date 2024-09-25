/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:19:11 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 10:34:43 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char	*string = "This is string";
	int	number = 42;
	int	*ptr = &number;
	void	*voidptr = &string;
	unsigned int	ui = 999;

	printf("Showing the string output:      %-s\n", string);
	printf("Showing the %%p output:%p\n", ptr);
	printf("Showing the void %%p output:%p\n", voidptr);
	printf("Showing the %%i output: %+d \n", number);
	printf("showing the %%ui output: %u\n", ui);
	printf("Showing the x output: %#x\n", number);
	printf("showing the X output: %X\n", number);
}
