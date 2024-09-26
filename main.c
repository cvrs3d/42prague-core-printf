/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:19:11 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 13:14:41 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

void    ft_putn_nbr(long number, int length)
{
        char    c;

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

int main(void)
{
	ft_putn_nbr(42, 3);
}
