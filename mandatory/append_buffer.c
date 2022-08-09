/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:19:57 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/10 01:10:03 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	copy_buffer(char *new_string, t_decoded *decoded, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < BUFFER)
	{
		j = 0;
		while (j < BYTE)
		{
			if (decoded->buffer[i][j] == 1)
				new_string[i + len] |= 1 << j;
			else
				new_string[i + len] &= ~(1 << j);
			j++;
		}
		if (new_string[i + len] == '\0')
		{
			decoded->finished = 1;
			return ;
		}
		i++;
	}
}

char	*append_buffer(t_decoded *decoded)
{
	char	*new_string;
	size_t	len;

	len = ft_strlen(decoded->string);
	new_string = (char *) malloc (sizeof (char) * (BUFFER + len + 1));
	if (!new_string)
		return (NULL);
	new_string[BUFFER + len] = '\0';
	ft_memcpy(new_string, decoded->string, len);
	copy_buffer(new_string, decoded, len);
	free (decoded->string);
	return (new_string);
}
