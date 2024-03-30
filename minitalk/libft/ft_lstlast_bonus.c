/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:30:54 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 17:02:19 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst, ft_lstnew("World"));
// 	t_list *last_con = ft_lstlast(lst);
// 	printf("content : %s",last_con->content);
// }