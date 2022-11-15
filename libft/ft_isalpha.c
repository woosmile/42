/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:03 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/15 16:12:38 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	c_temp;

	c_temp = c;
	if ((c_temp >= 'A' && 'Z' >= c_temp) || \
		(c_temp >= 'a' && c_temp <= 'z'))
		return (1);
	else
		return (0);
}