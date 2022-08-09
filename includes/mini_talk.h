/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:11:05 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/09 23:59:48 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

# define BUFFER 100
# define BYTE 8

typedef struct s_decoded
{
	int		buffer[BUFFER][BYTE];
	int		bit;
	char	*string;
	int		finished;
	int		sender;
	int		to_send;
}	t_decoded;

char	*append_buffer(t_decoded *decoded);

#endif
