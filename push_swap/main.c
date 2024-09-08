/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:45:52 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/08 18:07:28 by tsongtra         ###   ########.fr       */
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
	
}

int	main(int arc,char **arv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (arc < 2)
		return (0);
	check_arg(arc, arv);
	*stack_a = NULL;
	*stack_b = NULL;
	
	return (0);
}

