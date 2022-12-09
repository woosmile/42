/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:55:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/09 15:14:08 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_distributor(char c, va_list ap, int *len)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = print_char(va_arg(ap, int), len);
	else if (c == 's')
		result = print_str(va_arg(ap, char *), len);
	else if (c == 'p')
		result = print_addr(va_arg(ap, void *), len);
	else if (c == 'd' || c == 'i')
		result = print_nbr(va_arg(ap, int), len);
	else if (c == 'u')
		result = print_nbr_u(va_arg(ap, unsigned int), len);
	else if (c == 'x' || c == 'X')
		result = print_hex(va_arg(ap, unsigned int), len, c);
	else if (c == '%')
	{
		result = write(1, "%%", 1);
		(*len)++;
	}
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, s);
	len = 0;
	while (*s != 0)
	{
		if (*s == '%')
		{
			if (print_distributor(*(s + 1), ap, &len) == -1)
				return (-1);
			s = s + 2;
		}
		else
		{
			if (write(1, s, 1) == -1)
				return (-1);
			len++;
			s++;
		}
	}
	va_end(ap);
	return (len);
}
