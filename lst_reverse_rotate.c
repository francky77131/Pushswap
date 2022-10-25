/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:15:07 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:44:27 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	tmp = *list;
	last = ft_lstlast(*list);
	while ((*list)->next->next != NULL)
		*list = (*list)->next;
	last->next = tmp;
	before_last = *list;
	before_last->next = NULL;
	*list = last;
}

void	do_rra(t_list **a_list)
{
	ft_reverse_rotate(a_list);
	ft_printf("rra\n");
}

void	do_rrb(t_list **b_list)
{
	ft_reverse_rotate(b_list);
	ft_printf("rrb\n");
}

void	do_rrr(t_list **a_list, t_list **b_list)
{
	ft_reverse_rotate(a_list);
	ft_reverse_rotate(b_list);
	ft_printf("rrr\n");
}
