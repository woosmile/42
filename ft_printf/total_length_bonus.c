/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_length_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:16:54 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 13:49:24 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*variable_arg_length(char *s, va_list ap, t_options *options)
{
	int	va_len;

	va_len = 0;
	if (*s == 'c')
	{
		va_arg(ap, int);
		va_len = char_length(*options);
	}
	else if (*s == 's')
		va_len = str_length(va_arg(ap, char *), *options);
	else if (*s == 'p')
		va_len = addr_length(va_arg(ap, void *), *options);
	else if (*s == 'd' || *s == 'i')
		va_len = nbr_length(va_arg(ap, int), *options, *s);
	else if (*s == 'u')
		va_len = nbr_length(va_arg(ap, unsigned int), *options, *s);
	else if (*s == 'x' || *s == 'X')
		va_len = hex_length(va_arg(ap, unsigned int), *options, *s);
	if (*s != 0)
		s++;
	options->len = options->len + va_len;
	return (s);
}

void	total_length(char *s, va_list ap, t_options *options)
{
	options->len = 0;
	while (*s != 0)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
			{
				(options->len)++;
				s = s + 2;
			}
			else
			{
				s = check_options(s, options);
				s = variable_arg_length(s, ap, options);
			}
		}
		else
		{
			(options->len)++;
			s++;
		}
	}
}
