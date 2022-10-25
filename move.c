/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:38:59 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:10:41 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_list **a, t_list **b, int *costa, int *costb)
{
	while (*costa > 0 && *costb > 0)
	{
		(*costa)--;
		(*costb)--;
		do_rr(a, b);
	}
}

void	rev_rotate_ab(t_list **a, t_list **b, int *costa, int *costb)
{
	while (*costa < 0 && *costb < 0)
	{
		(*costa)++;
		(*costb)++;
		do_rrr(a, b);
	}
}

void	rotate_a(t_list **a_list, int *cost_a)
{
	if (*cost_a > 0)
	{
		while (*cost_a > 0)
		{
			do_ra(a_list);
			(*cost_a)--;
		}
	}
	else if (*cost_a < 0)
	{
		while (*cost_a < 0)
		{
			do_rra(a_list);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_list **b_list, int *cost_b)
{
	if (*cost_b > 0)
	{
		while (*cost_b > 0)
		{
			do_rb(b_list);
			(*cost_b)--;
		}
	}
	else if (*cost_b < 0)
	{
		while (*cost_b < 0)
		{
			do_rrb(b_list);
			(*cost_b)++;
		}
	}
}

void	ft_sort_size_three(t_list	**list)
{
	while (!((*list)->content < (*list)->next->content
			&& (*list)->next->content < (*list)->next->next->content))
	{
		if ((*list)->index > (*list)->next->index
			&& (*list)->index > (*list)->next->next->index)
			do_ra(list);
		else if ((*list)->next->index > (*list)->index
			&& (*list)->index > (*list)->next->next->index)
			do_rra(list);
		else if ((*list)->index < (*list)->next->next->index)
			do_sa(list);
	}
}
