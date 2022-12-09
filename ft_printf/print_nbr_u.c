/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:04:19 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/09 10:21:52 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_len_u(unsigned int n)
{
	int		n_len;

	n_len = 0;
	if (n == 0)
		n_len = 1;
	while (n > 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

void	input_number_u(unsigned int n, int n_len, char *num_arr)
{
	int		i;

	i = n_len - 1;
	if (n == 0)
		num_arr[0] = '0';
	while (i >= 0)
	{
		num_arr[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
}

int	print_nbr_u(unsigned int n, int *len)
{
	int		n_len;
	int		i;
	char	num_arr[10];
	int		result;

	n_len = check_len_u(n);
	i = 0;
	result = 0;
	while (i < 10)
	{
		num_arr[i] = 0;
		i++;
	}
	input_number_u(n, n_len, num_arr);
	result = write(1, num_arr, n_len);
	*len = *len + n_len;
	return (result);
}
