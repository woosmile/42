/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:55:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/08 16:01:07 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_distributor(char c, va_list ap, int *len)
{
	if (c == 'c')
		print_char(va_arg(ap, int), len);
	else if (c == 's')
		print_str(va_arg(ap, char *), len);
	else if (c == 'p')
		print_addr(va_arg(ap, void *), len);
	else if (c == 'd' || c == 'i')
		print_nbr(va_arg(ap, int), len);
	else if (c == 'u')
		print_nbr_u(va_arg(ap, unsigned int), len);
	else if (c == 'x' || c == 'X')
		print_hex (va_arg(ap, int), len, c);
	else if (c == '%')
	{
		write(1, "%%", 1);
		(*len)++;
	}
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
			print_distributor(*(s + 1), ap, &len);
			s = s + 2;
		}
		else
		{
			if (write(1, s, 1) == -1)
				return (0);
			len++;
			s++;
		}
	}
	va_end(ap);
	return (len);
}
