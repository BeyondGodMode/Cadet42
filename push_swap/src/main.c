/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:45:52 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/12 21:21:29 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_dup(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	while (head)
	{
		tail = head->next;
		while (tail)
		{
			if (head->value == tail->value)
			{
				free_stack(stack);
				ft_error("Error");
			}
			tail = tail->next;
		}
		head = head->next;
	}
}

static void	initstack(t_list **stack, int arc, char **arv)
{
	t_list	*new;
	char	**arg;
	int		i;
	int		j;

	i = 1;
	while (i < arc)
	{
		arg = ft_split(arv[i], ' ');
		j = 0;
		while (arg[j])
		{
			new = ft_lstnew(ft_atoi(arg[j]));
			ft_lstadd_back(stack, new);
			j++;
		}
		i++;
		ft_free(arg);
	}
	check_dup(stack);
	init_index(stack);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int arc, char **arv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (arc < 2)
		return (0);
	check_arg(arc, arv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	initstack(stack_a, arc, arv);
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_b = NULL;
	if (sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
