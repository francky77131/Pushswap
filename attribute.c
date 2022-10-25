/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:28:51 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 11:44:09 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_attribute_index(int *tab, t_list	**list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	while ((*list) != NULL)
	{
		i = 0;
		while (tab[i] != (*list)->content)
			i++;
		(*list)->index = i + 1;
		*list = (*list)->next;
	}
	*list = tmp;
}

void	ft_attribute_pos(t_list **list)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	if (!(*list))
		return ;
	while ((*list) != NULL)
	{
		(*list)->pos = i;
		*list = (*list)->next;
		i++;
	}
	*list = tmp;
}

void	if_tpos(t_list **a_list, t_list **b_list, t_list *max, t_list *min)
{
	(*b_list)->t_pos = 1;
	if ((*b_list)->index < min->index)
		(*b_list)->t_pos = min->pos;
	else if ((*b_list)->index > max->index)
		(*b_list)->t_pos = min->pos;
	else
	{
		while ((*a_list)->next != NULL)
		{
			if ((*b_list)->index > (*a_list)->index
				&& (*b_list)->index < (*a_list)->next->index)
				break ;
			(*b_list)->t_pos++;
			*a_list = (*a_list)->next;
		}
	}
}

void	ft_attribute_target_pos(t_list **a_list, t_list **b_list)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*max;
	t_list	*min;

	tmp_a = *a_list;
	tmp_b = *b_list;
	max = ft_find_max(a_list);
	min = ft_find_min(a_list);
	while (*b_list != NULL)
	{
		if_tpos(a_list, b_list, max, min);
		*a_list = tmp_a;
		*b_list = (*b_list)->next;
	}
	*a_list = tmp_a;
	*b_list = tmp_b;
}

void	ft_calculate_moove(t_list **a_list, t_list **b_list)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a_list;
	tmp_b = *b_list;
	size_a = ft_lstsize(*a_list);
	size_b = ft_lstsize(*b_list);
	while (*b_list != NULL)
	{
		(*b_list)->cost_b = (*b_list)->pos;
		if ((*b_list)->pos > size_b / 2)
			(*b_list)->cost_b = (size_b - (*b_list)->pos) * -1;
		(*b_list)->cost_a = (*b_list)->t_pos;
		if ((*b_list)->t_pos > size_a / 2)
			(*b_list)->cost_a = (size_a - (*b_list)->t_pos) * -1;
		*b_list = (*b_list)->next;
	}
	*a_list = tmp_a;
	*b_list = tmp_b;
}
