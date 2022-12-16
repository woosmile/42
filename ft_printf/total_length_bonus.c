/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_length_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:16:54 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/16 17:22:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*variable_arg_length(char *s, va_list ap, t_options options, int *len)
{
	int	va_len;

	va_len = 0;
	while (*s != 0)
	{
		if (*s == 'c')
			va_len = char_length(va_arg(ap, int), options);
		else if (*s == 's')
			va_len = str_length(va_arg(ap, char *), options);
		/*
		else if (*s == 'p')
			va_len = addr_length(va_arg(ap, void *), options);
		else if (*s == 'd' || *s == 'i' || *s == 'u')
			va_len = nbr_length(va_arg(ap, int), options);
		else if (*s == 'x' || *s == 'X')
			va_len = hex_length(va_arg(ap, int), s, options);
		else if (*s == '%')
			va_len = 1;
		*/
		s++;
		if (va_len > 0)
			break ;
	}
	*len = *len + va_len;
	return (s);
}

int	total_length(char *s, va_list ap, t_options *options)
{
	int	len;

	len = 0;
	while (*s != 0)
	{
		if (*s == '%')
		{
			check_options(s, options);
			s = variable_arg_length(s, ap, *options, &len);
		}
		else
		{
			len++;
			s++;
		}
	}
	return (len);
}
