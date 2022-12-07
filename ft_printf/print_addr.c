/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:26 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/07 17:58:44 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursion_value(unsigned long long addr_temp, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr_temp == 0)
		return ;
	else
	{
		recursion_value(addr_temp / 16, len);
		write (1, &hex[addr_temp % 16], 1);
		(*len)++;
	}
}

void	print_addr(void *addr, int *len)
{
	unsigned long long	addr_temp;

	addr_temp = (unsigned long long)addr;
	write (1, "0x", 2);
	*len = *len + 2;
	recursion_value(addr_temp, len);
}
