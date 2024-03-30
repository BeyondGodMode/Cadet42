/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:20:56 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 16:55:23 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}
// int	main()
// {
// 	t_list *elem = ft_lstnew("Hello");
// 	printf("%s\n",elem->content);
// 	ft_lstdelone(elem, free);
// }
