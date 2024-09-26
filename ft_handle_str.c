/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:04 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 11:43:37 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_str(const char *s, int slen)
{
	while (*s != '\0' && slen > 0)
	{
		write (STDOUT_FILENO, s, 1);
		s++;
		slen--;
	}
	return ;
}

static void	process_rightj(const char *s, int slen, int width, t_Config *c)
{
	if (c->pad_zero)
		ft_filln_with(width, '0');
	else
		ft_filln_with(width, ' ');
	put_str(s, slen);
}

int	ft_handle_str(t_Config *config, va_list ap)
{
	const char	*s;
	int			width;
	int			slen;

	s = (const char *)va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	slen = ft_strlen(s);
	if (config->precision > -1 && config->precision < slen)
		slen = config->precision;
	width = config->width - slen;
	if (width < 0)
		width = 0;
	if (config->left_justify == 1)
	{
		put_str(s, slen);
		ft_filln_with(width, ' ');
	}
	else
		process_rightj(s, slen, width, config);
	return (slen + width);
}
