/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:42:58 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 13:18:53 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	proc_rigth(t_Config *c, int i, int l, int w);
static void	proc_left(t_Config *c, int i, int l, int w);

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
	int	integer;
	int	ilen;
	int	width;

	integer = va_arg(ap, int);
	ilen = ft_numlen(integer);
	if (config->force_sign || config->space && integer > 0)
		ilen += 1;
	if (config->precision != -1
		&& config->precision > integer)
		ilen = config->prcision;
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
static void	proc_rigth(t_Config *c, int i, int l, int w)
{
	long	n;

	ft_put_sign(c, i);
	if (config->pad_zero == 1)
		ft_filln_with(w, '0');
	else if (config->space == 1 && c->force_sign != 1)
		ft_filln_with(w, ' ');
	n = (long)i;
	if (i < 0)
		n *= -1;
	ft_putn_nbr(n, l);
}

/*
 * Left alligned processing. Puts sign, then prints
 * out number with leading zeroes if precision   is
 * grater then ilen, then filling with <space>   to
 * the end of field length if any left. Zero   flag
 * is omitted due to - flag usage.
 */
static void	proc_left(t_Config *c, int i, int l, int w)
{
	long	n;

	ft_put_sign(c, i);
	n = (long)i;
	if (i < 0)
		n *= -1;
	ft_putn_nbr(n, l);
	ft_filln_with(w, ' ');
}
