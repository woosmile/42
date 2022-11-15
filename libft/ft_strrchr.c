/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:23:10 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/14 18:35:57 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_temp;
	char	c_temp;

	i = 0;
	s_temp = (char *)s;
	c_temp = c;
	if (c_temp == 0)
	{
		while (*s_temp != 0)
			s_temp++;
		return (s_temp);
	}
	while (s_temp[i] != 0)
		i++;
	while (i >= 0)
	{
		if (*(s_temp + i) == c)
			return (s_temp + i);
		i--;
	}
	return (0);
}
