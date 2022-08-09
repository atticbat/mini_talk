/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:19:42 by khatlas           #+#    #+#             */
/*   Updated: 2022/06/26 09:01:23 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_pp(void)
{
	char	*allocated;

	allocated = NULL;
	allocated = (char *) malloc (sizeof (char));
	if (!allocated)
		return (NULL);
	ft_memcpy(allocated, "%", 1);
	return (allocated);
}
