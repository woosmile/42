/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:15:47 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/14 18:35:49 by woosekim         ###   ########.fr       */
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
	while (*haystack != 0 && i < len)
	{
		if (*haystack == *needle)
		{
			j = 0;
			while ((*haystack == *needle) && *needle != 0)
			{
				haystack++;
				needle++;
				j++;
			}
			if (*needle == 0)
				return ((char *)(haystack - j));
		}
		haystack++;
		i++;
	}
	return (0);
}
