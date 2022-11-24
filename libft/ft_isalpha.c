/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:21:03 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/24 16:24:26 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	c_temp;

	c_temp = c;
	if ((c_temp >= 'A' && c_temp <= 'Z') || \
		(c_temp >= 'a' && c_temp <= 'z'))
		return (1);
	else
		return (0);
}
