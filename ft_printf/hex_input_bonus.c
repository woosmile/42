/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:46:26 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/28 18:28:31 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	right_hex_prec(char *hex_num, char *str, t_options options, t_var var)
{
	while (var.str_idx < var.str_len)
	{
		if (var.str_idx < var.str_len - var.s_len)
		{
			if (options.prec >= var.str_len - var.str_idx)
				str[var.str_idx] = '0';
			else
				str[var.str_idx] = ' ';
		}
		else
		{
			if (!(options.prec == 0 && hex_num[0] == '0'))
				str[var.str_idx] = hex_num[(var.s_idx)++];
			else
				str[var.str_idx] = ' ';
		}
		(var.str_idx)++;
	}
}

void	right_hex_width(char *hex_num, char *str, t_options options, t_var var)
{
	while (var.str_idx < var.str_len)
	{
		if (var.str_idx < var.str_len - var.s_len)
		{
			if (options.zero == 1)
				str[var.str_idx] = '0';
			else
				str[var.str_idx] = ' ';
		}
		else
			str[var.str_idx] = hex_num[(var.s_idx)++];
		(var.str_idx)++;
	}
}

void	left_hex_prec(char *hex_num, char *str, t_options options, t_var var)
{
	int	offset;

	if (options.prec < var.s_len)
		offset = (options.blank || options.plus);
	else
		offset = options.prec - var.s_len + (options.blank || options.plus);
	while (var.str_idx < var.str_len)
	{
		if (var.str_idx < offset)
			str[var.str_idx] = '0';
		else
		{
			if (!(options.prec == 0 && hex_num[0] == '0') && \
				(var.s_idx < var.s_len))
				str[var.str_idx] = hex_num[(var.s_idx)++];
			else
				str[var.str_idx] = ' ';
		}
		(var.str_idx)++;
	}
}

void	left_hex_width(char *hex_num, char *str, t_options options, t_var var)
{
	int	offset;

	offset = (options.blank || options.plus);
	while (var.str_idx < var.str_len)
	{
		if (var.s_idx < var.s_len)
			str[var.str_idx + offset] = hex_num[(var.s_idx)++];
		else
			str[var.str_idx + offset] = ' ';
		(var.str_idx)++;
	}
}