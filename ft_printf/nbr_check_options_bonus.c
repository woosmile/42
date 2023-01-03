/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_check_options_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:18 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/03 15:45:37 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	nbr_original_length(long num)
{
	int		len;

	len = 0;
	if (num == 0)
		len = 1;
	else if (num < 0)
	{
		len++;
		num = num * -1;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	negative_check(char *itoa)
{
	int	negative;

	negative = 0;
	if (itoa[0] == '-')
		negative = 1;
	return (negative);
}

int	offset_setting(t_options options, t_var var, long num)
{
	if (options.prec_flag == 1)
	{
		if (num == 0 && options.prec == 0)
			return (0);
		if (var.str_len == options.prec)
			return (0);
		else
			return (1);
	}
	else
	{
		if (var.str_len == var.s_len)
			return (0);
		else
			return (1);
	}
}

void	right_neg_input(char *str, t_options options, t_var var)
{
	if (options.prec_flag == 1)
	{
		if (options.prec < var.s_len)
			options.prec = var.s_len - 1;
		if (var.str_len == options.prec)
			(options.prec)--;
		str[var.str_len - options.prec - 1] = '-';
	}
	else
	{
		if (options.zero == 1)
			str[0] = '-';
		else
			str[var.str_len - var.s_len] = '-';
	}
}

void	right_pos_input(char *str, t_options options, t_var var, int offset)
{
	if (options.prec_flag == 1)
	{
		if (options.prec < var.s_len)
			options.prec = var.s_len;
		str[var.str_len - options.prec - offset] = ' ';
		if (options.plus == 1)
			str[var.str_len - options.prec - offset] = '+';
	}
	else
	{
		if (options.zero == 1)
		{
			str[0] = ' ';
			if (options.plus == 1)
				str[0] = '+';
		}
		else
		{
			str[var.str_len - var.s_len - offset] = ' ';
			if (options.plus == 1)
				str[var.str_len - var.s_len - offset] = '+';
		}
	}
}
