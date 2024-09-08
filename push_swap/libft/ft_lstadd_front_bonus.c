/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:21:03 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 16:04:27 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	t_list *new = ft_lstnew("World");
// 	ft_lstadd_front(&lst, new);
// 	printf("%s",lst->content);
// 	lst = lst->next;
// 	printf("%s",lst->content);
// }
