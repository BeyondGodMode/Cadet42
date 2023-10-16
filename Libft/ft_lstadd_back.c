/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:35:56 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 16:03:34 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	t_list *new = ft_lstnew("World");
// 	ft_lstadd_back(&lst, new);
// 	printf("%s",lst->content);
// 	lst = lst->next;
// 	printf("%s",lst->content);
// }