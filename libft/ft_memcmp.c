/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:31:31 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/06 17:23:39 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_temp = s1;
	const unsigned char	*s2_temp = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (s1_temp[i] != s2_temp[i])
			return ((int)s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (0);
}
