/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:38:32 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/28 16:45:26 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_temp;
	char	c_temp;
	size_t	i;

	s_temp = (char *)s;
	c_temp = c;
	i = 0;
	while (s_temp[i] != 0)
	{
		if (s_temp[i] == c_temp)
			return (s_temp + i);
		i++;
	}
	if (s_temp[i] == c_temp)
		return (s_temp + i);
	else
		return (0);
}
