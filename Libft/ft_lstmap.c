/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsongtra <tsongtra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:40:04 by tsongtra          #+#    #+#             */
/*   Updated: 2023/10/17 09:43:51 by tsongtra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (f == NULL || del == NULL || lst == NULL)
		return (NULL);
	first = NULL;
	while (lst != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
// void	*tranform_content(void *content)
// {
// 	if(content == NULL)
// 		return (NULL);
// 	char *str = (char *)content;
// 	char * result = ft_strdup(str);
// 	for (size_t i = 0; result[i]; i++)
// 	{
// 		result[i] = ft_toupper(result[i]);
// 	}
// 	return (result);
// }
// void	free_content(void *content)
// {
// 	free(content);
// }

// int	main()
// {
// 	t_list *lst = ft_lstnew("Hello");
// 	ft_lstadd_back(&lst,ft_lstnew("World"));
// 	t_list *new_lst = ft_lstmap(lst, tranform_content, free_content);
// 	printf("contents : %s",new_lst->content);
// }

// cc ft_lstmap.c ft_lstnew.c ft_lstclear.c
// ft_lstadd_back.c ft_toupper.c 
// ft_strdup.c ft_lstlast.c ft_strlcpy.c ft_strlen.c;./a.out