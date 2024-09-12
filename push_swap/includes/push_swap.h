/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:45:44 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/12 21:25:38 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);

void	ft_error(char *msg);
void	ft_error2(char *msg, char **arg);
void	check_arg(int arc, char **arv);
int		sorted(t_list **stack);
void	free_stack(t_list **stack);
void	ft_free(char **str);
int		is_whitespace(char c);
int		is_empty_or_whitespace(const char *str);

void	radix_sort(t_list **stack_a, t_list **stack_b);
void	small_sort(t_list **stack_a, t_list **stack_b);
void	init_index(t_list **stack);
int		get_distance(t_list **stack, int index);
int		get_max(t_list **stack, int val);

int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverserotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif