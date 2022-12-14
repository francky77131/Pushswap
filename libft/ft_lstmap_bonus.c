/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:56:44 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/14 16:47:25 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = ft_lstnew((*f)(lst->content));
	if (!newlst)
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	tmp = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		ft_lstadd_back(&tmp, ft_lstnew(f(lst->content)));
		if (!tmp->next)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (newlst);
}
