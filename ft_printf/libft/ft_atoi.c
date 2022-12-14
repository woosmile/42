/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:19:31 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/02 16:15:44 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_result(const char *str, int sign)
{
	int		result;
	long	result_l;
	long	check;

	result = 0;
	result_l = 0;
	check = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		result_l = (result_l * 10) + (*str - '0');
		if (sign == -1)
		{
			if (result_l < check)
				return (0);
		}
		else if (sign == 1)
		{
			if (result_l < check)
				return (-1);
		}
		check = result_l;
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (number_result(str, sign) * sign);
}
