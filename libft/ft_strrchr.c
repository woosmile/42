/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:23:10 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/28 17:02:38 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_temp;
	char	c_temp;
	size_t	i;

	s_temp = (char *)s;
	c_temp = c;
	i = 0;
	while (s_temp[i] != 0)
		i++;
	while (i >= 0)
	{
		if (s_temp[i] == c_temp)
			return (s_temp + i);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}
