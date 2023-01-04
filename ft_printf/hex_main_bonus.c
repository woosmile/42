/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:17:26 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 13:50:59 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	hex_original_length(unsigned int num, int *len)
{
	if (num == 0)
	{
		*len = 1;
		return ;
	}
	while (num > 0)
	{
		num = num / 16;
		(*len)++;
	}
}

int	hex_length(unsigned int num, t_options options, char c)
{
	int	len;

	if (!num && options.prec_flag && !options.width && !options.prec)
		return (0);
	len = 0;
	if (options.hash == 1 && num > 0)
	{
		len = 2;
		options.prec = options.prec + 2;
	}
	hex_original_length(num, &len);
	nbr_length_width_prec(num, options, c, &len);
	return (len);
}

void	hex_value_input(char *hex_num, char *str, t_options options, t_var var)
{
	if (options.minus == 0)
	{
		if (options.prec_flag == 1)
			right_hex_prec(hex_num, str, options, var);
		else
			right_hex_width(hex_num, str, options, var);
	}
	else
	{
		if (options.prec_flag == 1)
			left_hex_prec(hex_num, str, options, var);
		else
			left_hex_width(hex_num, str, options, var);
	}
}

char	*hex_itoa(unsigned int num, int len, char c)
{
	char		*hex_itoa;
	char		*hex_lower;
	char		*hex_upper;
	int			i;

	hex_itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex_itoa)
		return (0);
	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	i = len - 1;
	while (i >= 0)
	{
		if (c == 'x')
			hex_itoa[i] = hex_lower[num % 16];
		else if (c == 'X')
			hex_itoa[i] = hex_upper[num % 16];
		num = num / 16;
		i--;
	}
	hex_itoa[len] = 0;
	return (hex_itoa);
}

char	*hex_input(unsigned int num, char *str, t_options options, char c)
{
	t_var	var;
	char	*hex_num;

	if (!(!num && options.prec_flag && !options.width && !options.prec))
	{
		var.s_idx = 0;
		var.s_len = 0;
		hex_original_length(num, &var.s_len);
		var.str_idx = 0;
		var.str_len = hex_length(num, options, c);
		hex_num = hex_itoa(num, var.s_len, c);
		if (!hex_num)
			return (str);
		hex_value_input(hex_num, str, options, var);
		if (options.hash && num != 0)
			hash_input(str, options, var, c);
		free(hex_num);
		return (str + var.str_len);
	}
	return (str);
}
