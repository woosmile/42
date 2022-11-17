/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:05:10 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/17 18:30:59 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_tail_length(char const *s1, char const *set, \
									size_t len_s1)
{
	size_t	i;
	size_t	len_tail;

	i = 0;
	len_tail = 0;
	s1 = s1 + (len_s1 - 1);
	while (set[i] != 0)
	{
		if (*s1 == set[i])
		{
			s1--;
			len_tail++;
			i = 0;
		}
		else
			i++;
	}
	return (len_tail);
}

static size_t	check_head_length(char const *s1, char const *set, \
									size_t len_s1, size_t len_tail)
{
	size_t	i;
	size_t	len_head;

	i = 0;
	len_head = 0;
	while (set[i] != 0 && len_s1 > len_tail)
	{
		if (*s1 == set[i])
		{
			s1++;
			len_head++;
			i = 0;
		}
		else
			i++;
	}
	return (len_head);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	len_head;
	size_t	len_tail;
	size_t	i;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_tail = check_tail_length(s1, set, len_s1);
	len_head = check_head_length(s1, set, len_s1, len_tail);
	i = 0;
	str = (char *)malloc((len_s1 - len_head - len_tail + 1) * sizeof(char));
	if (!str)
		return (0);
	s1 = s1 + len_head;
	while (i + len_head < len_s1 - len_tail)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
