/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:44:52 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/24 12:54:48 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*tab;
	t_list	*a_list;
	t_list	*b_list;

	a_list = NULL;
	b_list = NULL;
	if (argc >= 2)
	{
		tab = malloc(sizeof(tab) * (argc - 1));
		if (!tab)
			return (write(2, "Error\n", 6));
		if (check_error(tab, argc, argv) == 1)
			return (write(2, "Error\n", 6));
		if (create_list(argc, tab, &a_list) == 1)
			return (write(2, "Error\n", 6));
		ft_sort_int_tab(tab, argc - 1);
		ft_attribute_index(tab, &a_list);
		if (check_order(&a_list, tab) == 1)
			return (0);
		ft_push_swap(&a_list, &b_list, argc);
		free(tab);
		free_lst(&a_list);
	}
	return (0);
}

void	ft_push_swap(t_list **a_list, t_list **b_list, int argc)
{
	int	i;

	i = (argc - 1) / 2;
	if (argc == 4)
	{
		ft_sort_size_three(a_list);
		return ;
	}
	else if (argc == 3)
	{
		do_sa(a_list);
		return ;
	}
	else if (argc > 4)
		ft_allpush_b(argc, i, a_list, b_list);
	while (ft_lstsize(*b_list) != 0)
	{
		ft_attribute_pos(a_list);
		ft_attribute_pos(b_list);
		ft_attribute_target_pos(a_list, b_list);
		ft_calculate_moove(a_list, b_list);
		cheap_move(a_list, b_list);
	}
	ft_last_move(a_list);
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;

	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
