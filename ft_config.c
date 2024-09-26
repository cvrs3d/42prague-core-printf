/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:38:16 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 13:54:38 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * Here is place where config packet      for
 * the convertion types is being initialized.
 * Explanatory on default 	      values:
 * left_justify - 0 is for default      right
 * allignment, 1 is for left;
 * width - contains MINIMAL field width to be
 * outputted the length of type to be inserted
 * is included;
 * pad_zero - 0 default, if 1 printf    should
 * fill lasting width with zeroes. Ignored
 * when - is passed.
 * precision - <minus>1 if not present, if 0
 * nothing is printed. Specifies how many chars
 * to prints.
 * hex_form - 0 default if 1 prints hex values
 * and pointers in 0xFFFFFFFF; form.
 * space - 0 default, if 1 fills field with <space>
 * if place left. Is ignored when + passed or 0
 * is specified. Also is similar to + flag for ints.
 * force_sign - 0 default, if 1 prints out + on 
 * positive numbers.
 * specifier - 't' for defaulT, is ascii code char
 * for handling convertion type.
 */
t_Config	*initialize_config(void)
{
	t_Config	*c;

	c = (t_Config *)malloc(sizeof(t_Config));
	if (c == NULL)
		return (NULL);
	c->left_justify = 0;
	c->width = 0;
	c->pad_zero = 0;
	c->precision = -1;
	c->hex_form = 0;
	c->space = 0;
	c->force_sign = 0;
	c->specifier = 't';
	return (c);
}
