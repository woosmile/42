/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:22 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/02 17:03:35 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_length(char *s, t_options options)
{
	int	s_len;
	int	len;

	if (options.prec_flag == 1 && options.width == 0 && options.prec == 0)
		return (0);
	if (s == 0)
		s_len = 6;
	else
		s_len = ft_strlen(s);
	len = 0;
	if (options.prec_flag == 1)
	{
		len = options.prec;
		if (len > s_len)
			len = s_len;
		if (options.width > len)
			len = options.width;
	}
	else
	{
		len = s_len;
		if (options.width > len)
			len = options.width;
	}
	return (len);
}

int	right_str(char *s, char *str, t_options options, t_var var)
{
	if (options.prec_flag == 1)
	{
		while (var.str_idx < var.str_len)
		{
			if (var.str_idx < var.str_len - options.prec)
				str[(var.str_idx)++] = ' ';
			else
				str[(var.str_idx)++] = s[(var.s_idx)++];
		}
	}
	else
	{
		while (var.str_idx < var.str_len)
		{
			if (var.str_idx < var.str_len - var.s_len)
				str[(var.str_idx)++] = ' ';
			else
				str[(var.str_idx)++] = s[(var.s_idx)++];
		}
	}
	return (var.str_idx);
}

int	left_str(char *s, char *str, t_options options, t_var var)
{
	if (options.prec_flag == 1)
	{
		while (var.str_idx < var.str_len)
		{
			if (var.str_idx < options.prec)
				str[(var.str_idx)++] = s[(var.s_idx)++];
			else
				str[(var.str_idx)++] = ' ';
		}
	}
	else
	{
		while (var.str_idx < var.str_len)
		{
			if (var.str_idx < var.s_len)
				str[(var.str_idx)++] = s[(var.s_idx)++];
			else
				str[(var.str_idx)++] = ' ';
		}
	}
	return (var.str_idx);
}

char	*str_input(char *s, char *str, t_options options)
{
	t_var	var;
	char	*s_temp;

	if (options.prec_flag == 1 && options.width == 0 && options.prec == 0)
		return (str);
	if (s == 0)
		s_temp = "(null)";
	else
		s_temp = s;
	var.s_idx = 0;
	var.s_len = ft_strlen(s_temp);
	var.str_idx = 0;
	var.str_len = str_length(s_temp, options);
	if (options.prec > var.s_len)
		options.prec = var.s_len;
	if (options.minus == 0)
		var.str_idx = right_str(s_temp, str, options, var);
	else
		var.str_idx = left_str(s_temp, str, options, var);
	return (str + var.str_idx);
}
