/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:04:19 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/14 17:21:31 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	nbr_original_length(long num)
{
	int		len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
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

int	nbr_length(long num, t_options options, char c)
{
	int	r_len;

	r_len = nbr_original_length(num);
	if (r_len < options.width || r_len < options.prec)
	{
		if (options.width > options.prec)
			r_len = options.width;
		else
		{
			r_len = options.prec;
			if (c != 'u' && (options.blank || options.plus))
				r_len++;
		}
	}
	else
	{
		if (num > 0 && c != 'u' && (options.blank || options.plus))
			r_len++;
	}
	return (r_len);
}

void	right_nbr(char *str, char *itoa, t_options *options, t_var *var)
{
	int	negative;

	negative = 0;
	if (itoa[0] == '-')
		negative = 1;

	if (options->prec_flag == 1)
	{
		while (var->str_idx < var->str_len)
		{
			if (var->str_idx < var->str_len - var->s_len + negative)
			{
				if (options->prec > var->str_len - var->str_idx)
					str[var->str_idx] = '0';
				else
					str[var->str_idx] = ' ';
			}
			else
				str[var->str_idx] = itoa[negative + (var->s_idx)++];
			(var->str_idx)++;
		}
		if (options->plus == 1 && negative == 0)
		{
			if (options->prec < var->s_len)
				str[var->str_len - var->s_len - 1] = '+';
			else
				str[var->str_len - options->prec - 1] = '+';
		}
		if (negative == 1)
		{
			if (options->prec < var->s_len)
				str[var->str_len - var->s_len - 1] = '-';
			else
				str[var->str_len - options->prec - 1] = '-';
		}
	}
	else
	{
		while (var->str_idx < var->str_len)
		{
			if (var->str_idx < var->str_len - var->s_len)
			{
				if (options->zero == 1)
					str[var->str_idx] = '0';
				else
					str[var->str_idx] = ' ';
			}
			else
				str[var->str_idx] = itoa[negative + (var->s_idx)++];
			(var->str_idx)++;
		}
	}
	
}

char	*nbr_input(long num, char *str, t_options options, char c)	//width, prec_flag, ' ', 0, +, -
{
	char	*itoa;
	t_var	var;

	itoa = ft_itoa(num);
	var.s_idx = 0;
	var.s_len = nbr_original_length(num);
	var.str_idx = 0;
	var.str_len = nbr_length(num, options, c);
	if (options.minus == 0)
		right_nbr(str, itoa, &options, &var);
	//else
	//	left_nbr(str, itoa, options, &var);
	free(itoa);
	return (str + var.str_len);
}