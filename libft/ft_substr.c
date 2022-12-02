/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:39:57 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/29 17:05:43 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sub_len;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) > len)
		sub_len = len;
	else
		sub_len = ft_strlen(s + start);
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
