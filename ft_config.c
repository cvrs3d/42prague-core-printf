/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:38:16 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 10:46:01 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
