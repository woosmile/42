/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:51:29 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/14 19:09:43 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	char_length(char c, t_options *options)
{
	int	len;

	if (options->width > 0)
		len = options->width;
	else
		len = 1;
	return (len);
}

void	char_input(char c, char *str, t_options options)
{
	int	i;
	if (options.width == 0)
		str[0] = c;
	else
	{
		if (options.minus == 1)
		{
			i = 1;
			str[0] = c;
			while (i < options.width)
			{
				str[i] = ' ';
				i++;
			}
		}
		else
		{
			i = options.width - 1;
			while (i >= 0)
			{
				str[i] = ' ';
				i--;
			}
			str[i] = c;
		}
	}
}