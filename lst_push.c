/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:14:59 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:44:24 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **a_list, t_list **b_list)
{
	t_list	*second;

	second = (*a_list)->next;
	if (*b_list == NULL)
	{
		*b_list = *a_list;
		(*b_list)->next = NULL;
	}
	else
		ft_lstadd_front(b_list, *a_list);
	*a_list = second;
}

void	do_pb(t_list **a_list, t_list **b_list)
{
	ft_push(b_list, a_list);
	ft_printf("pa\n");
}

void	do_pa(t_list **a_list, t_list **b_list)
{
	ft_push(a_list, b_list);
	ft_printf("pb\n");
}
