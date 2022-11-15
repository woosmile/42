/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:38:32 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/14 18:36:08 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_temp;
	char	c_temp;

	s_temp = (char *)s;
	c_temp = c;
	if (c_temp == 0)
	{
		while (*s_temp != 0)
			s_temp++;
		return (s_temp);
	}
	while (*s_temp != 0)
	{
		if (*s_temp == c)
			return (s_temp);
		s_temp++;
	}
	return (0);
}
