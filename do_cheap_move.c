/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheap_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:11:20 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:11:44 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_move(t_list **a_list)
{
	int		size;
	t_list	*min_index;
	int		min_pos;

	size = ft_lstsize(*a_list);
	min_index = ft_find_min(a_list);
	min_pos = 0;
	min_pos = min_index->pos;
	if (min_pos > size / 2)
	{
		while ((*a_list)->index != 1)
			do_ra(a_list);
	}
	else
		while ((*a_list)->index != 1)
			do_rra(a_list);
}

void	cheap_move(t_list **a_list, t_list **b_list)
{
	t_list	*tmp_b;
	int		cost_a;
	int		cost_b;
	int		cost_ab;

	tmp_b = *b_list;
	cost_a = 0;
	cost_b = 0;
	cost_ab = INT_MAX;
	while (*b_list)
	{
		if ((negpos((*b_list)->cost_a) + negpos((*b_list)->cost_b)) < cost_ab)
		{
			cost_ab = negpos((*b_list)->cost_a) + negpos((*b_list)->cost_b);
			cost_a = (*b_list)->cost_a;
			cost_b = (*b_list)->cost_b;
		}
		*b_list = (*b_list)->next;
	}
	*b_list = tmp_b;
	do_move(a_list, b_list, cost_a, cost_b);
}

void	do_move(t_list **a_list, t_list **b_list, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_ab(a_list, b_list, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_ab(a_list, b_list, &cost_a, &cost_b);
	if (cost_a != 0)
		rotate_a(a_list, &cost_a);
	if (cost_b != 0)
		rotate_b(b_list, &cost_b);
	do_pb(a_list, b_list);
}
