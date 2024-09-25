/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:17:25 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 13:42:19 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* Handler for single char is defined here;
 * Arguments: It accepts 2 args, config and va_list;
 * Behavior: It should, based on the config foramt and 
 * write char to the console;
 * It gets its char from va_list, if type mismatch behavior is 
 * undefined(SEGFAULT);
 * Return: Returns width of field that was written in console;*/
static void	filln_in_with(int n, char c);

int	ft_handle_char(t_Config *config, va_list ap)
{
	char	c;
	int		width;

	c = (char)va_arg(ap, int);
	if (config->precision == 0)
		return (0);
	width = config->width - 1;
	if (config->left_justify)
	{
		write (STDOUT_FILENO, &c, 1);
		filln_in_with(width, ' ');
	}
	else
	{
		if (config->pad_zero)
			filln_in_with(width, '0');
		else
			filln_in_with(width, ' ');
	}
	write (STDOUT_FILENO, &c, 1);
	if (config->width > 0)
		return (config->width);
	return (1);
}

static void	filln_in_with(int n, char c)
{
	while (n-- > 0)
		write(STDOUT_FILENO, &c, 1);
	return ;
}
