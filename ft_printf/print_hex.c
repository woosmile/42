/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:26 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/09 09:57:25 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	input_hex_value(unsigned int n, char *arr, int n_len, char c)
{
	int		i;
	char	*hex;

	i = n_len - 1;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	while (i >= 0)
	{
		arr[i] = hex[n % 16];
		n = n / 16;
		i--;
	}
}

int	print_hex(unsigned int n, int *len, char c)
{
	int		result;
	int		n_len;
	char	*arr;

	result = 0;
	n_len = 0;
	if (n == 0)
	{
		result = write(1, "0", 1);
		(*len)++;
	}
	else
	{
		n_len = check_hex_len(n);
		arr = (char *)malloc(n_len * sizeof(char));
		if (!arr)
			return (-1);
		input_hex_value(n, arr, n_len, c);
		result = write(1, arr, n_len);
		*len = *len + n_len;
		free(arr);
	}
	return (result);
}
