/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:05 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/30 14:57:26 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*uc_dst;
	const unsigned char	*cuc_src = src;
	size_t				i;

	if (!dst && !src)
		return (0);
	uc_dst = dst;
	i = 0;
	while (i < len)
	{
		if (uc_dst > cuc_src)
			uc_dst[len - i - 1] = cuc_src[len - i - 1];
		else
			uc_dst[i] = cuc_src[i];
		i++;
	}
	return (dst);
}
