/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:35:52 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/06 17:24:30 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_len(int n)
{
	size_t	len;
	long	n_temp;

	len = 0;
	n_temp = n;
	if (n_temp == 0)
		len = 1;
	if (n_temp < 0)
		len++;
	if (n_temp < 0)
		n_temp = n_temp * -1;
	while (n_temp > 0)
	{
		n_temp = n_temp / 10;
		len++;
	}
	return (len);
}

static void	input_number(int n, size_t len, char *num_arr)
{
	long	n_temp;
	int		i;

	n_temp = n;
	i = len - 1;
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

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	size_t	i;
	char	num_arr[11];

	if (fd == -1)
		return ;
	len = check_len(n);
	i = 0;
	while (i < 11)
	{
		num_arr[i] = 0;
		i++;
	}
	input_number(n, len, num_arr);
	i = len - 1;
	write (fd, num_arr, len);
}
