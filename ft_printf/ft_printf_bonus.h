/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:08:00 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/19 18:23:39 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_options
{
	int	width;
	int	prec;
	int	prec_flag;
	int	minus;
	int	zero;
	int	hash;
	int	blank;
	int	plus;
	int	len;
}	t_options;

typedef struct s_var
{
	int	s_idx;
	int	s_len;
	int	str_idx;
	int	str_len;
}	t_var;

int		ft_printf(const char *s, ...);
int		total_length(char *s, va_list ap, t_options *options);
char	*check_options(char *s, t_options *options);
int		char_length(t_options options);
char	*char_input(char c, char *str, t_options options);
int		str_length(char *s, t_options options);
char	*str_input(char *s, char *str, t_options *options);
int		addr_length(void *addr,	t_options options);
char	*addr_input(void *addr, char *str, t_options options);
int		nbr_length(long num, t_options options, char c);
char	*nbr_input(long num, char *str, t_options options, char c);

#endif