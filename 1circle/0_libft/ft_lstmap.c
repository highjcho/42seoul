/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:55:53 by hyunjcho          #+#    #+#             */
/*   Updated: 2021/12/09 16:46:58 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void *(*f)(void	*), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;

	if (!lst || !f)
		return (0);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (0);
	new_lst = new;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew((*f)(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (new);
}
