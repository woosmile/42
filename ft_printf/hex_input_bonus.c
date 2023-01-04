/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:46:26 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 15:16:56 by woosekim         ###   ########.fr       */
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

	offset = options.prec - 1;
	if ((options.prec < var.s_len) && (hex_num[0] != '0'))
		offset = (options.blank || options.plus || options.hash) + options.hash;
	else if ((options.prec >= var.s_len) && (hex_num[0] != '0'))
		offset = options.prec - var.s_len + \
		(options.blank || options.plus || options.hash) + options.hash;
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

	if (hex_num[0] == '0')
		offset = 0;
	else
		offset = (options.blank || options.plus || options.hash) + options.hash;
	while (var.str_idx < var.str_len)
	{
		if (var.s_idx < var.s_len)
			str[var.str_idx + offset] = hex_num[(var.s_idx)++];
		else
		{
			if (var.str_idx + offset < var.str_len)
				str[var.str_idx + offset] = ' ';
		}
		(var.str_idx)++;
	}
}

void	hash_input(char *str, t_options options, t_var var, char c)
{
	if (options.minus)
	{
		str[0] = '0';
		str[1] = c;
		return ;
	}
	if (options.prec_flag)
	{
		if (options.prec < var.s_len)
			options.prec = var.s_len;
		str[var.str_len - options.prec - 2] = '0';
		str[var.str_len - options.prec - 1] = c;
	}
	else
	{
		if (options.zero)
		{
			str[0] = '0';
			str[1] = c;
			return ;
		}
		str[var.str_len - var.s_len - 2] = '0';
		str[var.str_len - var.s_len - 1] = c;
	}
}
