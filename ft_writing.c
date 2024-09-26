/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:38:30 by yustinov          #+#    #+#             */
/*   Updated: 2024/09/26 11:49:58 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_filln_with(int fieldsize, char chr)
{
        while (fieldsize > 0)
	{
                write(STDOUT_FILENO, &chr, 1);
		fieldsize--;
	}
        return ;
}

