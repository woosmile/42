/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:04:19 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/04 15:19:06 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	nbr_length_width_prec(long num, t_options options, char c, int *r_len)
{
	if (options.prec_flag == 1)
	{
		if (options.width > options.prec && options.width > *r_len)
		{
			*r_len = options.width;
			return (1);
		}
		else if (options.prec >= *r_len)
		{
			*r_len = options.prec;
			if (c != 'u' && c != 'x' && c != 'X' && \
			(options.blank || options.plus || (num < 0)))
				(*r_len)++;
			return (1);
		}
	}
	else if (options.width > *r_len)
	{
		*r_len = options.width;
		return (1);
	}
	return (0);
}

int	nbr_length(long num, t_options options, char c)
{
	int	r_len;

	if (num == 0 && options.prec_flag == 1 && options.width == 0 && \
		options.prec == 0 && options.blank == 0 && options.plus == 0)
		return (0);
	r_len = nbr_original_length(num);
	if (nbr_length_width_prec(num, options, c, &r_len))
		return (r_len);
	if (num >= 0 && c != 'u' && (options.blank || options.plus))
		r_len = r_len + 1 \
		- (!num && options.prec_flag && (options.blank || options.plus));
	return (r_len);
}

void	nbr_value_input(char *str, char *itoa, t_options options, t_var var)
{
	if (options.minus == 0)
	{
		if (options.prec_flag == 1)
			right_nbr_prec(str, itoa, options, var);
		else
			right_nbr_width(str, itoa, options, var);
	}
	else
	{
		if (options.prec_flag == 1)
			left_nbr_prec(str, itoa, options, var);
		else
			left_nbr_width(str, itoa, options, var);
	}
}

void	neg_pos_input(long num, char *str, t_options options, t_var var)
{
	int	offset;

	if (options.minus == 0)
	{
		if (num < 0)
			right_neg_input(str, options, var);
		else if ((options.blank == 1 || options.plus == 1) && num >= 0)
		{
			offset = offset_setting(options, var, num);
			right_pos_input(str, options, var, offset);
		}
	}
	else
	{
		if (num < 0)
			str[0] = '-';
		if (options.blank == 1 && num >= 0)
			str[0] = ' ';
		if (options.plus == 1 && num >= 0)
			str[0] = '+';
	}
}

char	*nbr_input(long num, char *str, t_options options, char c)
{
	char	*itoa;
	t_var	var;

	if (!(num == 0 && options.prec_flag == 1 && options.width == 0 && \
		options.prec == 0 && options.blank == 0 && options.plus == 0))
	{
		itoa = ft_itoa(num);
		if (!itoa)
			return (str);
		var.s_idx = 0;
		var.s_len = nbr_original_length(num);
		var.str_idx = 0;
		var.str_len = nbr_length(num, options, c);
		nbr_value_input(str, itoa, options, var);
		if (c != 'u')
			neg_pos_input(num, str, options, var);
		free(itoa);
		return (str + var.str_len);
	}
	return (str);
}
