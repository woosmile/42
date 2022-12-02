/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:39:44 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/02 16:04:19 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_temp;

	lst_temp = *lst;
	if (new != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			while ((*lst)->next != 0)
				*lst = (*lst)->next;
			(*lst)->next = new;
			*lst = lst_temp;
		}
	}
}
