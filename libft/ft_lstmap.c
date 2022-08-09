/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:54:43 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 20:58:13 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*buffer;

	if (lst == NULL)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		buffer = ft_lstnew((*f)(lst->content));
		if (!buffer)
		{
			ft_lstclear(&head, del);
			free (head);
			free (buffer);
			return (NULL);
		}
		ft_lstadd_back(&head, buffer);
		lst = lst->next;
	}
	return (head);
}
//
// void    *f(void *content)
// {
// 	char  *ptr;
//  
//     ptr = (char *) content;
//     *ptr = 'a';
// 	return(content);
// }
//
// void    del(void *content)
// {
//     char  *ptr;
// 
//     ptr = (char *) content;
//     *ptr = '\0';
// }
//
// #include <stdio.h>
//
// int main()
// {
//   char    g[15] = "Achim";
//   char    w[8] = "Doush";
//   char    p[8] = "Kevin";
//   char    u[8] = "Jan";
//     t_list *head;
//   //  head = ft_lstnew(w);
//   //  ft_lstadd_front(&head, ft_lstnew(g));
//    // ft_lstadd_front(&head, ft_lstnew(p));
//     head = NULL;
//     ft_lstadd_back(&head, ft_lstnew(p));
//     ft_lstadd_back(&head, ft_lstnew(w));
//     ft_lstadd_back(&head, ft_lstnew(g));
//     ft_lstmap(head, f, del);
//   return 0;
// }
