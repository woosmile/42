/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:41 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/10 17:20:15 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*uc_s;

	i = 0;
	uc_s = s;
	if (n == 0)
		return ;
	while (i < n)
	{
		uc_s[i] = 0;
		i++;
	}
}
