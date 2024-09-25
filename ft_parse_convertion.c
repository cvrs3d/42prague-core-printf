/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_convertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:22:28 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 11:03:18 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* TODO: Implement following: 
int	ft_parse_convertion(const char **format, va_list ap)
It should go through the string of convertion (% +-0.0[a-z])
until it encounters an alpha. Respectively incrementig (*format)
so in the printf it will start next cycle iteration after specifier.
Should pass all the config to t_Config struct. It should be freed later.
*/

int	ft_parse_convertion(const char **format, va_list ap)
{
	t_Config	*config;

	config = initialize_config();
	if (config = NULL)
		return (-1);
	while (**format != '\0' && ft_is_alpha(**format) == 0)
	{
		if (**format == '-')
			config->left_justify = 1;
		if (**format == '+')
			config->force_sign = 1;
		if (**format == '#')
			config->hex_form = 1;
		if (**format == ' ')
			config->space = 1;
		if (**format == '0')
			config->pad_zero = proc_zero(format);
		if (**format == '.')
			config->precision = proc_precs(format);
	       (*format)++;
	}
	config->(char)(**format);
	return (handler(config, ap));
}

/*TODO: Implement int proc_zero(const char **f);
 * and int proc_precs(const char **f);
 * according to the printf C documentation*/
