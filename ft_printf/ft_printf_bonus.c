/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:07:29 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 11:58:36 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*conversion_selector(char c, va_list ap, char *str, t_options options)
{
	if (c == 'c')
		str = char_input(va_arg(ap, int), str, options);
	else if (c == 's')
		str = str_input(va_arg(ap, char *), str, options);
	else if (c == 'p')
		str = addr_input(va_arg(ap, char *), str, options);
	else if (c == 'd' || c == 'i')
		str = nbr_input(va_arg(ap, int), str, options, c);
	else if (c == 'u')
		str = nbr_input(va_arg(ap, unsigned int), str, options, c);
	else if (c == 'x' || c == 'X')
		str = hex_input(va_arg(ap, int), str, options, c);
	return (str);
}

void	conversion_input(char *s, va_list ap, char *str, t_options *options)
{
	while (*s != 0)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
			{
				*str = *s;
				str++;
				s = s + 2;
			}
			else
			{
				s = check_options(s, options);
				str = conversion_selector(*s, ap, str, *options);
				if (*s != 0)
					s++;
			}
		}
		else
		{
			*str = *s;
			str++;
			s++;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	char		*str;
	t_options	options;
	char		*s_temp;

	va_start(ap, s);
	s_temp = (char *)s;
	total_length(s_temp, ap, &options);
	str = (char *)malloc(sizeof(char) * options.len);
	if (!str)
	{
		va_end(ap);
		return (-1);
	}
	va_start(ap, s);
	conversion_input(s_temp, ap, str, &options);
	if (write(1, str, options.len) == -1)
	{
		va_end(ap);
		free(str);
		return (-1);
	}
	va_end(ap);
	free(str);
	return (options.len);
}
