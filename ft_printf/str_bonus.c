/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/16 18:22:39 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_length(char *s, t_options options)
{
	int	s_len;
	int	len;

	s_len = ft_strlen(s);
	len = 0;
	if (options.prec_flag == 1)
	{
		if (options.width > 0)
			len = options.width;
		else
			len = options.prec;
	}
	else
	{
		if (options.width > s_len)
			len = options.width;
		else
			len = s_len;
	}
	return (len);
}

char	*str_input(char *s, char *str, t_options *options)
{
	int	s_idx;
	int	s_len;
	int	str_idx;
	int	str_len;

	s_idx = 0;
	s_len = ft_strlen(s);
	str_idx = 0;
	str_len = str_length(s, *options);
	if (options->prec > s_len)
		options->prec = s_len;
	if (options->minus == 0)
	{
		if (options->prec_flag == 1)
		{
			while (str_idx < str_len)
			{
				if (str_idx < str_len - options->prec)
					str[str_idx++] = ' ';
				else
					str[str_idx++] = s[s_idx++];
			}
		}
		else
		{
			while (str_idx < str_len)
			{
				if (str_idx < str_len - s_len)
					str[str_idx++] = ' ';
				else
					str[str_idx++] = s[s_idx++];
			}
		}
	}
	return (str + str_idx);
}
