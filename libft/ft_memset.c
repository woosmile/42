/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:10:18 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/14 16:43:15 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c_temp;
	unsigned char	*p;

	i = 0;
	c_temp = c;
	p = b;
	while (i < len)
	{
		p[i] = c_temp;
		i++;
	}	
	return (b);
}
