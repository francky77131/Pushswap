/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:45:31 by frgojard          #+#    #+#             */
/*   Updated: 2022/10/21 11:48:01 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

int			check_char(char *av);
int			check_double(int *tab, int len);
void		ft_lst_swap(t_list **list);
void		ft_rotate(t_list **list);
void		ft_reverse_rotate(t_list **list);
void		ft_push(t_list **a_list, t_list **b_list);
int			check_error(int *tab, int argc, char **argv);
int			create_list(int argc, int *tab, t_list **a_list);
void		ft_attribute_index(int *tab, t_list	**list);
int			check_order(t_list **list, int *tab);
void		ft_sort_size_three(t_list	**list);
void		ft_allpush_b(int len, int med, t_list **a_list, t_list **b_list);
void		ft_attribute_pos(t_list **list);
void		ft_attribute_target_pos(t_list **a_list, t_list **b_list);
t_list		*ft_find_min(t_list **a_list);
t_list		*ft_find_max(t_list **a_list);
void		ft_calculate_moove(t_list **a_list, t_list **b_list);
void		do_sa(t_list **a_list);
void		do_sb(t_list **b_list);
void		do_ss(t_list **a_list, t_list **b_list);
void		do_ra(t_list **a_list);
void		do_rb(t_list **b_list);
void		do_rr(t_list **a_list, t_list **b_list);
void		do_rra(t_list **a_list);
void		do_rrb(t_list **b_list);
void		do_rrr(t_list **a_list, t_list **b_list);
void		do_pa(t_list **a_list, t_list **b_list);
void		do_pb(t_list **a_list, t_list **b_list);
int			negpos(int nb);
void		cheap_move(t_list **a_list, t_list **b_list);
void		do_move(t_list **a_list, t_list **b_list, int cost_a, int cost_b);
void		ft_last_move(t_list **a_list);
void		if_tpos(t_list **a_list, t_list **b_list, t_list *max, t_list *min);
void		rotate_ab(t_list **a, t_list **b, int *costa, int *costb);
void		rev_rotate_ab(t_list **a, t_list **b, int *costa, int *costb);
void		rotate_a(t_list **a_list, int *cost_a);
void		rotate_b(t_list **b_list, int *cost_b);
void		ft_push_swap(t_list **a_list, t_list **b_list, int argc);
void		free_lst(t_list **lst);
#endif
