/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:14:03 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/17 18:53:02 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_len(int n)
{
	int		len;
	long	n_temp;

	len = 0;
	n_temp = n;
	if (n == 0)
		len = 1;
	if (n < 0)
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

void	input_number(int n, int len, char *str_num)
{
	long	n_temp;
	int		i;

	n_temp = n;
	i = len - 1;
	if (n_temp == 0)
		str_num[0] = '0';
	if (n_temp < 0)
	{
		str_num[0] = '-';
		n_temp = n_temp * -1;
	}
	while (n_temp > 0)
	{
		str_num[i] = (n_temp % 10) + '0';
		n_temp = n_temp / 10;
		i--;
	}
	str_num[len] = 0;
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str_num;
	int		i;

	len = check_len(n);
	str_num = (char *)malloc((len + 1) * sizeof(char));
	if (!str_num)
		return (0);
	input_number(n, len, str_num);
	return (str_num);
}
