/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:11:05 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/14 16:42:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*uc_dst;
	const unsigned char	*cuc_src = src;
	unsigned char		buffer;
	size_t				i;

	uc_dst = dst;
	buffer = 0;
	i = 0;
	while (i < len)
	{
		buffer = cuc_src[i];
		uc_dst[i] = buffer;
		i++;
	}
	return (dst);
}
