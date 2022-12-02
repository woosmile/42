/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:18 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/02 16:04:23 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	if (*lst != 0 && del != 0)
	{
		while (curr != 0)
		{
			next = curr->next;
			ft_lstdelone(curr, del);
			curr = next;
		}
		*lst = 0;
	}
}
