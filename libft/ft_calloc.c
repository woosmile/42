/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:06:07 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/06 17:16:33 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	if ((count * size) / size != count)
		return (0);
	arr = (unsigned char *)malloc(count * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < count * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
