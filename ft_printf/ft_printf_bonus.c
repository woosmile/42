/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:07:29 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/19 18:23:04 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*conversion_selector(char c, va_list ap, char *str, t_options *options)
{
	if (c == 'c')
		str = char_input(va_arg(ap, int), str, *options);
	else if (c == 's' && !(options->prec_flag == 1 && options->width == 0 \
	&& options->prec == 0))
		str = str_input(va_arg(ap, char *), str, options);
	else if (c == 'p')
		str = addr_input(va_arg(ap, char *), str, *options);
	return (str);
}

void	conversion_input(char *s, va_list ap, char *str, t_options *options)
{
	while (*s != 0)
	{
		if (*s == '%')
		{
			s = check_options(s, options);
			str = conversion_selector(*s, ap, str, options);
			s++;
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
	options.len = total_length(s_temp, ap, &options);
	str = (char *)malloc(sizeof(char) * options.len);
	if (!str)
		return (0);
	va_start(ap, s);
	conversion_input(s_temp, ap, str, &options);
	if (write (1, str, options.len) == -1)
		return (-1);
	va_end(ap);
	free(str);
	return (options.len);
}
