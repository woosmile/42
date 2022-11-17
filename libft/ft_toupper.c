/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:06:50 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/17 12:55:18 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	c_temp;

	c_temp = c;
	if (c_temp >= 'a' && c_temp <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}
