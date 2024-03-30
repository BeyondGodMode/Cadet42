/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:28:14 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 16:44:00 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}

// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst, ft_lstnew("World"));

// 	// printf("%s",lst->content);
// 	ft_lstclear(&lst,free);
// 	printf("%s\n",lst->content);
// }
