/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:39:20 by frgojard          #+#    #+#             */
/*   Updated: 2022/03/15 16:08:06 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tempo;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i +1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tempo = tab[i];
				tab[i] = tab[j];
				tab[j] = tempo;
			}
			j++;
		}
		i++;
	}
}

/*int main()
{
	int tab[] = {5, 4, 3, 1};
	int size = 5;
	ft_sort_int_tab(tab, size);
}*/
