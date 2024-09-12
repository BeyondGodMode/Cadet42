/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:46:11 by tsongtra          #+#    #+#             */
/*   Updated: 2024/09/12 21:24:28 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isnum(char *num)
{
	int		i;

	i = 0;
	if ((num[0] == '-' && ft_isdigit(num[1])) \
	|| (num[0] == '+' && ft_isdigit(num[1])))
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_or_whitespace(const char *str)
{
	if (str == NULL || *str == '\0')
		return (1);
	while (*str)
	{
		if (!is_whitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'\
	|| c == '\r' || c == '\v' || c == '\f');
}

void	check_arg(int arc, char **arv)
{
	int		i;
	int		j;
	long	tmp;
	char	**arg;

	i = 1;
	while (i < arc)
	{
		if (is_empty_or_whitespace(arv[i]))
			ft_error("Error");
		arg = ft_split(arv[i++], ' ');
		j = 0;
		while (arg[j])
		{
			tmp = ft_atoi(arg[j]);
			if (!ft_isnum(arg[j]))
				ft_error2("Error", arg);
			if (tmp < -2147483648 || tmp > 2147483647)
				ft_error2("Error", arg);
			j++;
		}
		ft_free(arg);
	}
}
