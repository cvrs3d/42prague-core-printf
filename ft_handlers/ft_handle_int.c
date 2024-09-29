/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:42:58 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/29 13:30:09 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
//#include <stdio.h>

static void	proc_right(t_Config *c, long long i, int l, int w);
static void	proc_left(t_Config *c, long long i, int l, int w);

/* 
 * Handling integers and decimal     (they are same);
 * First of all computes length of number          to
 * print, then adjusts it with precision - ATTENTION!
 * it works like minimal length of int to be  printed
 * when we adjust the ilen we can compute field width
 * Then delegate work to processing handlers for left
 * justifying and right accordingly. Returns width of
 * field plus ilen anyways.
 */
int	ft_handle_int(t_Config *config, va_list ap)
{
	long long	integer;
	int			ilen;
	int			width;

	integer = (long long)va_arg(ap, int);
	ilen = ft_numlen(integer);
	if (config->precision != -1
		&& config->precision > ilen)
		ilen = config->precision;
	if ((config->force_sign || config->space) && integer > 0)
		ilen += 1;
	if (integer == 0)
		ilen += 1;
	width = config->width - ilen;
	if (width < 0)
		width = 0;
	if (config->left_justify == 1)
		proc_left(config, integer, ilen, width);
	if (config->left_justify == 0)
		proc_right(config, integer, ilen, width);
	return (ilen + width);
}

/*
 * Puts a sign before digit or any leading chars if
 * + is passed then ' ' flag is ignored if field is
 * bigger than number than pads it with   specified
 * characters 0 or <space> then outputs number with
 * leading zeroes if precision is greater then ilen
 */
static void	proc_right(t_Config *c, long long i, int l, int w)
{
	if (c->pad_zero == 1)
		ft_filln_with(w, '0');
	else if (c->force_sign != 1)
		ft_filln_with(w, ' ');
	ft_put_sign(c, i);
	if (c->force_sign == 1 || i < 0 || c->space == 1)
		l--;
	if (i < -9223372036854775807)
	{
		write (STDOUT_FILENO, "9223372036854775808", 19);
		return ;
	}
	if (i < 0)
		i *= -1;
	ft_putn_nbr(i, l);
}

/*
 * Left alligned processing. Puts sign, then prints
 * out number with leading zeroes if precision   is
 * grater then ilen, then filling with <space>   to
 * the end of field length if any left. Zero   flag
 * is omitted due to - flag usage.
 */
static void	proc_left(t_Config *c, long long i, int l, int w)
{
	ft_put_sign(c, i);
	if (c->force_sign == 1 || i < 0 || c->space == 1)
		l--;
	if (i < -9223372036854775807)
	{
		write (STDOUT_FILENO, "9223372036854775808", 19);
		return ;
	}
	if (i < 0)
		i *= -1;
	ft_putn_nbr(i, l);
	ft_filln_with(w, ' ');
}
