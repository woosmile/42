/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:48:00 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/24 16:08:14 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	s1_temp;
	unsigned char	s2_temp;

	i = 0;
	while (*s1 != 0 && *s2 != 0 && i < n)
	{
		s1_temp = *s1;
		s2_temp = *s2;
		if (s1_temp != s2_temp)
			return (s1_temp - s2_temp);
		s1++;
		s2++;
		i++;
	}
	s1_temp = *s1;
	s2_temp = *s2;
	return (s1_temp - s2_temp);
}
