/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:04:19 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/09 09:41:50 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_len(int n)
{
	int		n_len;
	long	n_temp;

	n_len = 0;
	n_temp = n;
	if (n_temp == 0)
		n_len = 1;
	if (n_temp < 0)
		n_len++;
	if (n_temp < 0)
		n_temp = n_temp * -1;
	while (n_temp > 0)
	{
		n_temp = n_temp / 10;
		n_len++;
	}
	return (n_len);
}

void	input_number(int n, int n_len, char *num_arr)
{
	long	n_temp;
	int		i;

	n_temp = n;
	i = n_len - 1;
	if (n_temp == 0)
		num_arr[0] = '0';
	if (n_temp < 0)
		n_temp = n_temp * -1;
	while (i >= 0)
	{
		num_arr[i] = (n_temp % 10) + '0';
		n_temp = n_temp / 10;
		i--;
	}
	i++;
	if (n < 0)
		num_arr[i] = '-';
}

int	print_nbr(int n, int *len)
{
	int		n_len;
	int		i;
	char	num_arr[11];
	int		result;

	n_len = check_len(n);
	i = 0;
	result = 0;
	while (i < 11)
	{
		num_arr[i] = 0;
		i++;
	}
	input_number(n, n_len, num_arr);
	result = write (1, num_arr, n_len);
	*len = *len + n_len;
	return (result);
}
