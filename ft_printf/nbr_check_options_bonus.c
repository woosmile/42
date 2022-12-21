/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_check_options_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:18 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/21 17:45:31 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	negative_check(char *itoa)
{
	int	negative;

	negative = 0;
	if (itoa[0] == '-')
		negative = 1;
	return (negative);
}

void	right_neg_input(char *str, t_options *options, t_var *var)
{
	if (options->prec_flag == 1)
	{
		if (options->prec < var->s_len)
			options->prec = var->s_len - 1;
		if (var->str_len == options->prec)
			(options->prec)++;
		str[var->str_len - options->prec - 1] = '-';
	}
	else
	{
		if (options->zero == 1)
			str[0] = '-';
		else
			str[var->str_len - var->s_len] = '-';
	}
}

void	right_pos_input(char *str, t_options *options, t_var *var)
{
	if (options->prec_flag == 1)
	{
		if (options->prec < var->s_len)
			options->prec = var->s_len - 1;
		str[var->str_len - options->prec - 1] = ' ';
		if (options->plus == 1)
			str[var->str_len - options->prec - 1] = '+';
	}
	else
	{
		if (options->zero == 1)
		{
			str[0] = ' ';
			if (options->plus == 1)
				str[0] = '+';
		}
		else
		{
			str[var->str_len - var->s_len - 1] = ' ';
			if (options->plus == 1)
				str[var->str_len - var->s_len - 1] = '+';
		}
	}
}
