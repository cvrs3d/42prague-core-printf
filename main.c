/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:19:11 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 13:26:45 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    // 1. Basic Conversion Tests

    // Character %c
    printf("Character (printf): %c\n", 'A');
    ft_printf("Character (ft_printf): %c\n", 'A');

    // String %s
    printf("String (printf): %s\n", "Hello, World!");
    ft_printf("String (ft_printf): %s\n", "Hello, World!");

    // Pointer %p
    int x = 42;
    printf("Pointer (printf): %p\n", &x);
    ft_printf("Pointer (ft_printf): %p\n", &x);

    // Decimal/Integer %d %i
    printf("Decimal (printf): %d\n", 123);
    ft_printf("Decimal (ft_printf): %d\n", 123);
    printf("Integer (printf): %i\n", -456);
    ft_printf("Integer (ft_printf): %i\n", -456);

    // Unsigned Decimal %u
    printf("Unsigned (printf): %u\n", 12345U);
    ft_printf("Unsigned (ft_printf): %u\n", 12345U);

    // Hexadecimal %x %X
    printf("Hex lowercase (printf): %x\n", 255);
    ft_printf("Hex lowercase (ft_printf): %x\n", 255);
    printf("Hex uppercase (printf): %X\n", 255);
    ft_printf("Hex uppercase (ft_printf): %X\n", 255);
    // Percent Sign %%
    printf("Percent (printf): %%\n");
    ft_printf("Percent (ft_printf): %%\n");


    // 2. Flag and Width Tests

    // Left-justify flag %-
    printf("Left justify (printf): %-10d|\n", 123);
    ft_printf("Left justify (ft_printf): %-10d|\n", 123);

    // Zero-padding %0
    printf("Zero pad (printf): %010d\n", 123);
    ft_printf("Zero pad (ft_printf): %010d\n", 123);

    // Precision with integers %.
    printf("Precision (printf): %.5d\n", 42);
    ft_printf("Precision (ft_printf): %.5d\n", 42);

    // Width with precision %width.precision
    printf("Width and precision (printf): %10.5d\n", 42);
    ft_printf("Width and precision (ft_printf): %10.5d\n", 42);

    // Flags: #, +, and space
    printf("Hex with # (printf): %#x\n", 255);
    ft_printf("Hex with # (ft_printf): %#x\n", 255);

    printf("Force sign with + (printf): %+d\n", 42);
    ft_printf("Force sign with + (ft_printf): %+d\n", 42);

    printf("Space (printf): % d\n", 42);
    ft_printf("Space (ft_printf): % d\n", 42);

    printf("Unsigned with negative passed (printf): %u\n", -42);
    ft_printf("Unsigned with negative passed (ft_print): %u\n", -42);

    printf("Zero passed (printf): %d\n", 0);
    ft_printf("Zero passed (ft_print): %d\n", 0);

    printf("Integer 0 (printf): %d\n", 0);
    ft_printf("Integer 0 (ft_printf): %d\n", 0);

    printf("Long MIN (printf): %d\n", 9223372036854775807LL);
    ft_printf("Long MIN (ft_printf): %d\n", 9223372036854775807LL);

    printf("Mixed specifiers (printf): %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    ft_printf("Mixed specifiers (ft_printf): %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);


    return 0;
}

