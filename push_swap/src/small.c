/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:48:38 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/12 21:22:33 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_list **stack_a, t_list **stack_b, int max)
{
	t_list	*head;
	t_list	*tail;
	int		min;

	min = get_min(stack_a, -1);
	head = *stack_a;
	tail = ft_lstlast(head);
	if (tail->index != max)
	{
		if (head->index == max)
			ra(stack_a);
		else if (head->index == min)
			pb(stack_a, stack_b);
		else
			rra(stack_a);
	}
	head = *stack_a;
	if (head->index > head->next->index)
		sa(stack_a);
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;
	int	max;

	max = get_max(stack_a, -1);
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a, stack_b, max);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (sorted(stack_a) || ft_lstsize(*stack_a) == 0 \
	|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ra(stack_a);
	else if (size == 3)
		sort_3(stack_a, stack_b, 2);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
