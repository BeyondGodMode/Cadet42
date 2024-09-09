/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:45:52 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/09 13:43:26 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initstack(t_list **stack, int arc, char **arv)
{
	t_list	*new;
	char	**arg;
	int		i;

	i = 0;
	if (arc == 2)
		arg = ft_split(arv[1], ' ');
	else
	{
		i = 1;
		arg = arv;
	}
	while (arg[i])
	{
		new = ft_lstnew(ft_atoi(arg[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (arc == 2)
		ft_free(arg);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
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
	*stack_a = NULL;
	*stack_b = NULL;
	initstack(stack_a, arc, arv);
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

