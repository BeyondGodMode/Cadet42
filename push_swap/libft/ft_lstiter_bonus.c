/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:33:35 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/16 16:59:06 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	print_content(void *content)
// {
// 	printf ("Contents : %s\n",(char *)content);
// }

// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst,ft_lstnew("World"));
// 	ft_lstiter(lst, print_content);
// }
