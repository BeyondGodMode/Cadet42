/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:46:11 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/08 13:46:39 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_contains(int num, char **arv, int i)
{
	i++;
	while (arv[i])
	{
		if (ft_atoi(arv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int		i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int arc, char **arv)
{
	int		i;
	long	tmp;
	char	**arg;

	i = 0;
	if (arc == 2)
		arg == ft_split(arg[1], ' ');
	else
	{
		i = 1;
		arg = arv;
	}
	while (arg[i])
	{
		tmp = ft_atoi(arg[i]);
		if (!ft_isnum(arg[i]))
			ft_error("input error please input numbers!!");
		if (check_contains(tmp, arg, i))
			ft_error("Input error duplicate number!!");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Input error input overflow !!");
		i++;
	}
	if (arc == 2)
		ft_free(arg);
}
