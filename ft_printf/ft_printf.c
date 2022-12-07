/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:55:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/07 18:03:28 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_distributor(char c, va_list ap, int *len)
{
	int	temp;

	if (c == 'c')
	{
		temp = va_arg(ap, int);
		write(1, &temp, 1);
		(*len)++;
	}
	else if (c == 's')
		print_str(va_arg(ap, char *), len);
	else if (c == 'p')
		print_addr(va_arg(ap, void *), len);
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
			write(1, s, 1);
			len++;
			s++;
		}
	}
	va_end(ap);
	return (len);
}
