/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:02:11 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/08 16:33:49 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
void	print_char(char c, int *len);
void	print_str(char *s, int *len);
void	print_addr(void *addr, int *len);
void	print_nbr(int n, int *len);
void	print_nbr_u(unsigned int n, int *len);
void	print_hex(unsigned int n, int *len, char c);

#endif
