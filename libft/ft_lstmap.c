/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:04 by woosekim          #+#    #+#             */
/*   Updated: 2022/11/24 10:39:16 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;
	t_list	*new;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
	{
		ft_lstdelone(head, del);
		return (0);
	}
	curr = lst->next;
	while (curr != 0)
	{
		new = ft_lstnew(f(curr->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		curr = curr->next;
	}
	return (head);
}
