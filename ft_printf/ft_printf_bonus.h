/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:08:00 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/14 19:09:41 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "stdio.h"

typedef struct s_options
{
	int	width;
	int	prec;
	int	minus;
	int	zero;
	int	hash;
	int	blank;
	int	plus;
	int	len;
}	t_options;

int		ft_printf(const char *s, ...);
int		total_length(char *s, va_list ap, t_options *options);
void	check_options(char *s, t_options *options);
int		char_length(char c, t_options *options);
void	char_input(char c, char *str, t_options options);

#endif