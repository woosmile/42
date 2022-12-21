/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/21 13:44:11 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_length(char *s, t_options options)
{
	int	s_len;
	int	len;

	if (options.prec_flag == 1 && options.width == 0 && options.prec == 0)
		return (0);
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

void	right_str(char *s, char *str, t_options *options, t_var *var)
{
	if (options->prec_flag == 1)
	{
		while (var->str_idx < var->str_len)
		{
			if (var->str_idx < var->str_len - options->prec)
				str[(var->str_idx)++] = ' ';
			else
				str[(var->str_idx)++] = s[(var->s_idx)++];
		}
	}
	else
	{
		while (var->str_idx < var->str_len)
		{
			if (var->str_idx < var->str_len - var->s_len)
				str[(var->str_idx)++] = ' ';
			else
				str[(var->str_idx)++] = s[(var->s_idx)++];
		}
	}
}

void	left_str(char *s, char *str, t_options *options, t_var *var)
{
	if (options->prec_flag == 1)
	{
		while (var->str_idx < var->str_len)
		{
			if (var->str_idx < options->prec)
				str[(var->str_idx)++] = s[(var->s_idx)++];
			else
				str[(var->str_idx)++] = ' ';
		}
	}
	else
	{
		while (var->str_idx < var->str_len)
		{
			if (var->str_idx < var->s_len)
				str[(var->str_idx)++] = s[(var->s_idx)++];
			else
				str[(var->str_idx)++] = ' ';
		}
	}
}

char	*str_input(char *s, char *str, t_options *options)
{
	t_var	var;

	if (options->prec_flag == 1 && options->width == 0 && options->prec == 0)
		return (0);
	var.s_idx = 0;
	var.s_len = ft_strlen(s);
	var.str_idx = 0;
	var.str_len = str_length(s, *options);
	if (options->prec > var.s_len)
		options->prec = var.s_len;
	if (options->minus == 0)
		right_str(s, str, options, &var);
	else
		left_str(s, str, options, &var);
	return (str + var.str_idx);
}
