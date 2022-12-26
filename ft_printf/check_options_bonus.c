/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:47:32 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/26 17:18:26 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	initial_options(t_options *options)
{
	options->width = 0;
	options->prec = 0;
	options->prec_flag = 0;
	options->minus = 0;
	options->zero = 0;
	options->hash = 0;
	options->blank = 0;
	options->plus = 0;
}

char	*check_flag(char *s, t_options *options)
{
	while (*s != 0 && *s != '.' && !(*s >= '1' && *s <= '9') && \
	(*s != 'c' && *s != 's' && *s != 'p' && *s != 'i' && *s != 'u' && \
	*s != 'd' && *s != 'x' && *s != 'X'))
	{
		s++;
		if (*s == '-')
			options->minus = 1;
		else if (*s == '0')
			options->zero = 1;
		else if (*s == '#')
			options->hash = 1;
		else if (*s == ' ')
			options->blank = 1;
		else if (*s == '+')
			options->plus = 1;
	}
	return (s);
}

char	*check_prec(char *s, t_options *options)
{
	while (*s != 0 && (*s != 'c' && *s != 's' && *s != 'p' && *s != 'i' && \
	*s != 'u' && *s != 'd' && *s != 'x' && *s != 'X'))
	{
		if (*s == '.')
		{
			options->prec_flag = 1;
			if (*(s + 1) >= '0' && *(s + 1) <= '9')
				options->prec = ft_atoi(s + 1);
		}
		s++;
	}
	return (s);
}

char	*check_options(char *s, t_options *options)
{
	initial_options(options);
	s = check_flag(s, options);
	if (*s >= '1' && *s <= '9')
		options->width = ft_atoi(s);
	s = check_prec(s, options);
	return (s);
}
