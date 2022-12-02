/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:40:34 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/30 14:57:28 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*uc_dst;
	const unsigned char	*cuc_src = src;
	size_t				i;

	if (!dst && !src)
		return (0);
	uc_dst = dst;
	i = 0;
	while (i < n)
	{
		uc_dst[i] = cuc_src[i];
		i++;
	}
	return (dst);
}
