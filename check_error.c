/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:04:19 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/21 11:48:49 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(int *tab, int argc, char **argv)
{
	int	ret;
	int	i;
	int	j;

	ret = 1;
	i = 1;
	j = 0;
	while (argv[i])
	{
		if (check_char(argv[i]) == 1 || ft_atoi(argv[i]) < -2147483648
			|| ft_atoi(argv[i]) > 2147483647)
		{
			free(tab);
			return (ret);
		}
		tab[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (check_double(tab, argc - 1) == 1)
	{
		free(tab);
		return (ret);
	}
	return (0);
}

int	check_char(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (*str == '-')
	{
		if (len == 1)
			return (1);
		str++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_double(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] == tab[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_order(t_list **list, int *tab)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 1;
	while ((*list) != NULL)
	{
		if (i != (*list)->index)
		{
			*list = tmp;
			return (0);
		}
		*list = (*list)->next;
		i++;
	}
	*list = tmp;
	free(tab);
	free_lst(list);
	return (1);
}
