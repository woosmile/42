/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:39:57 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/17 12:54:51 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (*s != 0)
	{
		if (*s == start)
		{
			while ((*s != 0) && i < len)
			{
				substr[i] = *s;
				s++;
				i++;
			}
			break ;
		}
		s++;
	}
	substr[i] = 0;
	return (substr);
}