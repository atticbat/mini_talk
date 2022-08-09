/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:16:29 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/01 14:35:09 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*make_null(void)
{
	char	*allocated;

	allocated = NULL;
	allocated = (char *) malloc ((4) * sizeof(char));
	if (!allocated)
		return (NULL);
	ft_memcpy(allocated, "0x0\0", 4);
	return (allocated);
}

static char	*make_string(void *ptr)
{
	char	*allocated;
	char	*buffer;

	buffer = ft_itoa_base_u((unsigned long) ptr, "0123456789abcdef");
	if (!buffer)
		return (NULL);
	allocated = (char *) malloc ((ft_strlen(buffer) + 3) * sizeof (char));
	if (!allocated)
	{
		free (buffer);
		return (NULL);
	}
	ft_memcpy(allocated, "0x", 2);
	ft_memcpy(allocated + 2, buffer, ft_strlen(buffer) + 1);
	free (buffer);
	return (allocated);
}

char	*ft_parse_p(va_list args)
{
	void	*buffer;

	buffer = NULL;
	buffer = va_arg(args, void *);
	if (buffer == NULL)
		return (make_null());
	else
		return (make_string(buffer));
}
