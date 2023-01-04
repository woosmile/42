/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:39:53 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 15:35:24 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	right_nbr_prec(char *str, char *itoa, t_options options, t_var var)
{
	int	negative;

	negative = negative_check(itoa);
	while (var.str_idx < var.str_len)
	{
		if (var.str_idx < var.str_len - var.s_len + negative)
		{
			if (options.prec >= var.str_len - var.str_idx)
				str[var.str_idx] = '0';
			else
				str[var.str_idx] = ' ';
		}
		else
		{
			if (!(options.prec == 0 && itoa[0] == '0') && \
				(var.s_idx < var.s_len - negative))
				str[var.str_idx] = itoa[negative + (var.s_idx)++];
			else
				str[var.str_idx] = ' ';
		}
		(var.str_idx)++;
	}
}

void	right_nbr_width(char *str, char *itoa, t_options options, t_var var)
{
	int	negative;

	negative = negative_check(itoa);
	while (var.str_idx < var.str_len)
	{
		if (var.str_idx < var.str_len - var.s_len + negative)
		{
			if (options.zero == 1)
				str[var.str_idx] = '0';
			else
				str[var.str_idx] = ' ';
		}
		else
		{
			if (var.s_idx < var.s_len - negative)
				str[var.str_idx] = itoa[negative + (var.s_idx)++];
		}
		(var.str_idx)++;
	}
}

void	left_nbr_prec(char *str, char *itoa, t_options options, t_var var)
{
	int	negative;
	int	offset;

	negative = negative_check(itoa);
	if (options.prec < var.s_len)
		offset = (options.blank || options.plus || negative);
	else
		offset = options.prec - var.s_len + \
				(options.blank || options.plus || negative) + negative;
	while (var.str_idx < var.str_len)
	{
		if (var.str_idx < offset)
			str[var.str_idx] = '0';
		else
		{
			if (!(options.prec == 0 && itoa[0] == '0') && \
				(var.s_idx < var.s_len - negative))
				str[var.str_idx] = itoa[negative + (var.s_idx)++];
			else
				str[var.str_idx] = ' ';
		}
		(var.str_idx)++;
	}
}

void	left_nbr_width(char *str, char *itoa, t_options options, t_var var)
{
	int	negative;
	int	offset;

	negative = negative_check(itoa);
	offset = (options.blank || options.plus || negative);
	while (var.str_idx < var.str_len)
	{
		if (var.s_idx < var.s_len - negative)
			str[var.str_idx + offset] = itoa[negative + (var.s_idx)++];
		else
		{
			if (var.str_idx + offset < var.str_len)
				str[var.str_idx + offset] = ' ';
		}
		(var.str_idx)++;
	}
}
