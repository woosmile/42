/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:26 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/14 17:20:57 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_addr_len(unsigned long long addr_temp)
{
	int	len;

	len = 0;
	while (addr_temp > 0)
	{
		addr_temp = addr_temp / 16;
		len++;
	}
	return (len);
}

void	input_addr_value(unsigned long addr_temp, char *arr, int addr_len)
{
	int		i;
	char	*hex;

	i = addr_len - 1;
	hex = "0123456789abcdef";
	arr[0] = '0';
	arr[1] = 'x';
	while (i >= 2)
	{
		arr[i] = hex[addr_temp % 16];
		addr_temp = addr_temp / 16;
		i--;
	}
}

int	print_addr(void *addr, int *len)
{
	int					result;
	int					addr_len;
	char				*arr;
	unsigned long long	addr_temp;

	result = 0;
	addr_len = 0;
	addr_temp = (unsigned long long)addr;
	if (addr_temp == 0)
	{
		result = write(1, "0x0", 3);
		*len = *len + 3;
	}
	else
	{
		addr_len = check_addr_len(addr_temp) + 2;
		arr = (char *)malloc(addr_len * sizeof(char));
		if (!arr)
			return (-1);
		input_addr_value(addr_temp, arr, addr_len);
		result = write(1, arr, addr_len);
		*len = *len + addr_len;
		free(arr);
	}
	return (result);
}
