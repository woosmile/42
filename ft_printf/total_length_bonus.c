/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_length_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:16:54 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/22 20:50:10 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*variable_arg_length(char *s, va_list ap, t_options options, int *len)
{
	int	va_len;

	va_len = 0;

	if (*s == 'c')
	{
		va_arg(ap, int);
		va_len = char_length(options);
	}
	else if (*s == 's')
		va_len = str_length(va_arg(ap, char *), options);
	else if (*s == 'p')
		va_len = addr_length(va_arg(ap, void *), options);
	else if (*s == 'd' || *s == 'i')
		va_len = nbr_length(va_arg(ap, int), options, *s);
	else if (*s == 'u')
		va_len = nbr_length(va_arg(ap, unsigned int), options, *s);
	/*
	else if (*s == 'x' || *s == 'X')
		va_len = hex_length(va_arg(ap, int), s, options);
	else if (*s == '%')
		va_len = 1;
	*/
	if (*s != 0)
		s++;
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
			s = check_options(s, options);
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
