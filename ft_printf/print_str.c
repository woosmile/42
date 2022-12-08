/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/08 16:29:34 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(char *s, int *len)
{
	size_t	s_len;

	s_len = 0;
	s_len = ft_strlen(s);
	if (write (1, s, s_len) == -1)
		return ;
	*len = *len + s_len;
}
