/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:51:39 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/19 12:05:44 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_list(int argc, int *tab, t_list **a_list)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
	{
		if (*a_list == NULL)
		{
			*a_list = ft_lstnew(tab[i]);
			if (!tab)
			{
				free_lst(a_list);
				return (1);
			}
		}
		else
		{
			ft_lstadd_back((a_list), ft_lstnew(tab[i]));
			if (!tab)
			{
				free_lst(a_list);
				return (1);
			}
		}
	}
	return (0);
}

t_list	*ft_find_min(t_list **a_list)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *a_list;
	min = *a_list;
	while (*a_list != NULL)
	{
		if (min->index > (*a_list)->index)
			min = *a_list;
		*a_list = ((*a_list)->next);
	}
	*a_list = tmp;
	return (min);
}

t_list	*ft_find_max(t_list **a_list)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *a_list;
	max = *a_list;
	while (*a_list != NULL)
	{
		if (max->index < (*a_list)->index)
			max = *a_list;
		*a_list = ((*a_list)->next);
	}
	*a_list = tmp;
	return (max);
}

int	negpos(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_allpush_b(int len, int med, t_list **a_list, t_list **b_list)
{
	int	i;

	i = 0;
	while (i <= len && (*a_list)->next->next->next != NULL)
	{
		if ((*a_list)->index <= med)
			do_pa(a_list, b_list);
		else if ((*a_list)->index > med)
			do_ra(a_list);
		i++;
	}
	i = ft_lstsize(*a_list);
	while (i > 3)
	{
		do_pa(a_list, b_list);
		i--;
	}
	ft_sort_size_three(a_list);
}
