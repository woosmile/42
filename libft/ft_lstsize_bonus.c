/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:36:57 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/02 16:04:36 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*curr;

	size = 0;
	curr = lst;
	while (curr != 0)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}
