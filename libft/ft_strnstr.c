/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:15:47 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/30 15:33:28 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && \
			haystack[i + j] != 0 && needle[j] != 0 && i + j < len)
				j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
