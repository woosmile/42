/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:18 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/15 16:13:16 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	c_temp;

	c_temp = c;
	if ((c_temp >= 'A' && 'Z' >= c_temp) || \
		(c_temp >= 'a' && c_temp <= 'z') || \
		(c_temp >= '0' && c_temp <= '9'))
		return (1);
	else
		return (0);
}