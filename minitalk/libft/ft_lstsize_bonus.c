/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:26:14 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 17:24:00 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst, ft_lstnew("World"));
// 	ft_lstadd_back(&lst, ft_lstnew("Easy"));

// 	int size = ft_lstsize(lst);
// 	printf ("size : %d",size);
// 	// cc ft_lstsize.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c;./a.out 
// }