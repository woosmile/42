/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:31:37 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/23 17:35:33 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char const s, char c)
{
	int	result;

	if (s == c || s == 0)
		result = 1;
	else
		result = 0;
	return (result);
}

static size_t	string_count(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != 0)
	{
		if (check_sep(*s, c) == 0 && check_sep(*(s + 1), c) == 1)
			cnt++;
		s++;
	}
	return (cnt);
}

static int	word_count(char const *s, char c, char **str_arr, size_t str_cnt)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < str_cnt)
	{
		if (check_sep(*s, c) == 0)
			len++;
		if (check_sep(*s, c) == 0 && check_sep(*(s + 1), c) == 1)
		{
			str_arr[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!str_arr[i])
			{
				while (i >= 0)
					free(str_arr[--i]);
				return (0);
			}
			i++;
			len = 0;
		}
		s++;
	}
	return (1);
}

static void	word_input(char const *s, char c, char **str_arr, size_t str_cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		if (check_sep(*s, c) == 0)
		{
			str_arr[i][j] = *s;
			j++;
		}
		if (check_sep(*s, c) == 0 && check_sep(*(s + 1), c) == 1)
		{
			str_arr[i][j] = 0;
			i++;
			j = 0;
		}
		s++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	str_cnt;
	char	**str_arr;

	str_cnt = string_count(s, c);
	str_arr = (char **)malloc((str_cnt + 1) * sizeof(char *));
	if (!str_arr)
		return (0);
	if (!word_count(s, c, str_arr, str_cnt))
	{
		free(str_arr);
		return (0);
	}
	word_input(s, c, str_arr, str_cnt);
	str_arr[str_cnt] = 0;
	return (str_arr);
}
