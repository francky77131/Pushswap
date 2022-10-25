/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:15:13 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:44:31 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*last;

	tmp = (*list)->next;
	last = ft_lstlast(*list);
	last->next = *list;
	(*list) = last->next;
	(*list)->next = NULL;
	*list = tmp;
}

void	do_ra(t_list **a_list)
{
	ft_rotate(a_list);
	ft_printf("ra\n");
}

void	do_rb(t_list **b_list)
{
	ft_rotate(b_list);
	ft_printf("rb\n");
}

void	do_rr(t_list **a_list, t_list **b_list)
{
	ft_rotate(a_list);
	ft_rotate(b_list);
	ft_printf("rr\n");
}
