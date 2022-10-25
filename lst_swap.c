/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:12:19 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:44:35 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_swap(t_list **list)
{
	t_list	*tmp;
	t_list	*third;

	third = (*list)->next->next;
	tmp = (*list)->next;
	tmp->next = *list;
	(*list)->next = third;
	*list = tmp;
}

void	do_sa(t_list **a_list)
{
	ft_lst_swap(a_list);
	ft_printf("sa\n");
}

void	do_sb(t_list **b_list)
{
	ft_lst_swap(b_list);
	ft_printf("sb\n");
}

void	do_ss(t_list **a_list, t_list **b_list)
{
	ft_lst_swap(a_list);
	ft_lst_swap(b_list);
	ft_printf("ss\n");
}
