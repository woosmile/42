/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:16:04 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/02 16:04:34 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_node(t_list *lst, void *(*f)(void *), void (*del)(void *), \
						t_list *head)
{
	t_list	*new;
	void	*new_content;

	lst = lst->next;
	while (lst != 0)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			del(new_content);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*new_content;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	new_content = f(lst->content);
	head = ft_lstnew(new_content);
	if (!head)
	{
		del(new_content);
		return (0);
	}
	if (!next_node(lst, f, del, head))
		return (0);
	return (head);
}
