/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_convertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:22:28 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/25 17:12:55 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* Parser of the conversions, works with 7
 * optional flags. Unlike real printf,  it
 * tries to apply all possible flags    on
 * all possible convertion types it  works
 * with. Support added for %c, %s, %d,i %u
 * %x,X %p; Flags supported: - <space> + #
 * 0 * . ; Returns number of printed chars
*/

static int	proc_width(const char **f, t_Config *c, va_list ap);
static int	proc_precs(const char **f, t_Config *c, va_list ap);
static void	proc_zero(const char **f, t_Config *c, va_list ap);

int	ft_parse_convertion(const char **format, va_list ap)
{
	t_Config	*config;

	config = initialize_config();
	if (config == NULL)
		return (-1);
	while (**format != '\0' && ft_is_alpha(**format) == 0 && **format != '%')
	{
		if (**format == '-')
			config->left_justify = 1;
		if (**format == '+')
			config->force_sign = 1;
		if (**format == '#')
			config->hex_form = 1;
		if (**format == ' ' || **format == '0')
			proc_zero(format, config, ap);
		if (**format == '.')
			config->precision = proc_precs(format, config, ap);
		if (**format == '*' || ft_isdigit(**format))
			config->width = proc_width(format, config, ap);
		(*format)++;
	}
	config->(char)(**format);
	free(config);
	return (ft_handler(config, ap));
}

/* Proccess the width of the field
 * Goes through all the digits and 
 * calculates width of field being
 * outputed. Not safe in case   of
 * owerflow behavior        is not
 * defined(like in real printf   )
 * Returns minimal number of chars
 * to be printed.*/
static int	proc_width(const char **format, t_Config *cfg, va_list ap)
{
	int	width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			cfg->left_justify = 1;
			width = -width;
		}
	}
	else
	{
		while (ft_isdigit(**format))
		{
			width = width * 10 + (**format - '0');
			(*format)++;
		}
	}
	return (width);
}

static void	proc_zero(const char **format, t_Config *cfg, va_list ap)
{
	if (cfg->left_justify == 0 && **format == '0')
		cfg->pad_zero = 1;
	if (cfg->left_justify == 0 && **format == ' ')
		cfg->space = 1;
	(*format)++;
	if (ft_isdigit(**format) || **format == '*')
		config->width = proc_width(format, config, ap);
	return (cfg->pad_zero);
}

static int	proc_precs(const char **format, t_Config *c, va_list ap)
{
	int	precision;

	precision = 0;
	(*format)++;
	if (**format == '*')
		precision = va_arg(ap, int);
	else
	{
		while (ft_isdigit(**format))
		{
			presicion = precision * 10 + (**format - '0');
			(*format)++;
		}
	}
	if (precision < 0)
		precision = -1;
	return (precision);
}
