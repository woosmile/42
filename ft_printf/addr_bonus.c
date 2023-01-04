/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:26 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 14:42:02 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	addr_length(void *addr,	t_options options)
{
	int					addr_len;
	unsigned long long	addr_temp;

	addr_len = 0;
	addr_temp = (unsigned long long)addr;
	if (addr_temp == 0)
	{
		addr_len = 3;
		if (addr_len < options.width)
			addr_len = options.width;
	}
	else
	{
		while (addr_temp > 0)
		{
			addr_temp = addr_temp / 16;
			addr_len++;
		}
		addr_len = addr_len + 2;
		if (addr_len < options.width)
			addr_len = options.width;
	}
	return (addr_len);
}

int	addr_original_length(unsigned long long addr_temp)
{
	int	len;

	len = 0;
	if (addr_temp == 0)
		len = 1;
	while (addr_temp > 0)
	{
		addr_temp = addr_temp / 16;
		len++;
	}
	return (len);
}

void	right_addr(unsigned long long addr_temp, char *str, int addr_len)
{
	int		i;
	char	*hex;
	int		s_len;

	i = 0;
	hex = "0123456789abcdef";
	s_len = addr_original_length(addr_temp);
	while (i < addr_len - s_len - 2)
		*(str + i++) = ' ';
	*(str + i) = '0';
	*(str + i + 1) = 'x';
	i = addr_len - 1;
	while (i >= addr_len - s_len)
	{
		str[i] = hex[addr_temp % 16];
		addr_temp = addr_temp / 16;
		i--;
	}
}

void	left_addr(unsigned long long addr_temp, char *str, int addr_len)
{
	int		i;
	char	*hex;
	int		s_len;

	i = 0;
	hex = "0123456789abcdef";
	s_len = addr_original_length(addr_temp);
	*(str) = '0';
	*(str + 1) = 'x';
	i = s_len + 1;
	while (i >= 2)
	{
		str[i] = hex[addr_temp % 16];
		addr_temp = addr_temp / 16;
		i--;
	}
	i = s_len + 2;
	while (i < addr_len)
		*(str + i++) = ' ';
}

char	*addr_input(void *addr, char *str, t_options options)
{
	int					addr_len;
	unsigned long long	addr_temp;

	addr_len = addr_length(addr, options);
	addr_temp = (unsigned long long)addr;
	if (options.minus == 1)
		left_addr(addr_temp, str, addr_len);
	else
		right_addr(addr_temp, str, addr_len);
	return (str + addr_len);
}
