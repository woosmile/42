/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:40:40 by woosekim          #+#    #+#             */
/*   Updated: 2023/01/10 15:02:03 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				*buf;
	ssize_t				len;
	static ssize_t		row;

	len = 0;
	row = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (0);
	len = read(fd, buf, BUFFER_SIZE);
	buf[len - 1] = 0;
	while (*buf != 0)
	{
		if (*buf == '\n')
			row++;
		buf++;
	}
	return (buf);
}
