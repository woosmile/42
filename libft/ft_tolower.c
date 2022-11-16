/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:11:23 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/16 15:11:40 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	c_temp;

	c_temp = c;
	if (c_temp >= 'A' && c_temp <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}