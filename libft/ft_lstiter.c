/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:23:16 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 20:57:56 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*buffer;

	buffer = lst;
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			buffer = buffer->next;
			f(lst->content);
			lst = buffer;
		}
	}
}
