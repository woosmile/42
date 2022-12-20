/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:51:29 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/16 16:34:08 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	char_length(t_options options)
{
	int	len;

	if (options.width > 0)
		len = options.width;
	else
		len = 1;
	return (len);
}

char	*char_input(char c, char *str, t_options options)
{
	int	i;

	i = 1;
	if (options.width == 0)
		str[0] = c;
	else
	{
		if (options.minus == 0)
		{
			i = 0;
			while (i < options.width - 1)
				str[i++] = ' ';
			str[i] = c;
		}
		else
		{
			i = options.width - 1;
			while (i >= 1)
				str[i--] = ' ';
			str[i] = c;
		}
		i = options.width;
	}
	return (str + i);
}
