/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/09 09:41:48 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, int *len)
{
	size_t	s_len;
	int		result;

	s_len = 0;
	result = 0;
	if (!s)
	{
		result = write(1, "(null)", 6);
		*len = *len + 6;
	}
	else
	{
		s_len = ft_strlen(s);
		result = write(1, s, s_len);
		*len = *len + s_len;
	}
	return (result);
}
