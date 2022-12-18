/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:32:22 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/16 18:22:39 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_length(char *s, t_options options)
{
	int	s_len;
	int	len;

	s_len = ft_strlen(s);
	len = 0;
	if (options.prec_flag == 1)
	{
		if (options.width > 0)
			len = options.width;
		else
			len = options.prec;
	}
	else
	{
		if (options.width > s_len)
			len = options.width;
		else
			len = s_len;
	}
	return (len);
}

int	right_align(char *s, char *str, t_options *options, t_idx *idx)
{
	if (options->prec_flag == 1)
	{
		while (idx->str_idx < idx->str_len)
		{
			if (idx->str_idx < idx->str_len - options->prec)
				str[(idx->str_idx)++] = ' ';
			else
				str[(idx->str_idx)++] = s[(idx->s_idx)++];
		}
	}
	else
	{
		while (idx->str_idx < idx->str_len)
		{
			if (idx->str_idx < idx->str_len - idx->s_len)
				str[(idx->str_idx)++] = ' ';
			else
				str[(idx->str_idx)++] = s[(idx->s_idx)++];
		}
	}
}

int	left_align(char *s, char *str, t_options *options, t_idx *idx)
{

}

char	*str_input(char *s, char *str, t_options *options)
{
	t_idx	idx;

	idx.s_idx = 0;
	idx.s_len = ft_strlen(s);
	idx.str_idx = 0;
	idx.str_len = str_length(s, *options);
	if (options->prec > idx.s_len)
		options->prec = idx.s_len;
	if (options->minus == 0)
		right_align(s, str, options, &idx);
	else
		left_align(s, str, options, &idx);
	return (str + idx.str_idx);
}
