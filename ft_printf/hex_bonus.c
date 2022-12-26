/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:26 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/26 19:49:59 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hex_length(unsigned int num, t_options options, char c)
{
	int				len;
	unsigned int	num_temp;

	if (!num && options.prec_flag && !options.width && !options.prec)
		return (0);
	len = 0;
	if (options.hash == 1)
	{
		len = 2;
		options.prec = options.prec + 2;
	}
	num_temp = num;
	while (num_temp > 0)
	{
		num_temp = num_temp / 16;
		len++;
	}
	nbr_length_check_width_prec(num, options, c, &len);
	if (num != 0 && options.hash == 1 && (len < options.prec))
	{
		len = len + 2;
		if (len <= options.prec)
			len = options.prec;
	}
	return (len);
}
