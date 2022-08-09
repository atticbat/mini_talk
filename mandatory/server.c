/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:46:39 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/10 00:35:03 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <stdio.h>
#include <string.h>

t_decoded	g_decoded;

static int	find_null(void)
{
	int	i;

	i = 0;
	if (g_decoded.bit % BYTE != 0 || g_decoded.bit == 0)
		return (0);
	while (i < BYTE)
	{
		if (g_decoded.buffer[g_decoded.bit / BYTE - 1][i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	handler(int signum, siginfo_t *info, void *ignore)
{
	g_decoded.sender = info->si_pid;
	g_decoded.to_send = 1;
	if (signum == SIGUSR1)
	{
		g_decoded.buffer[g_decoded.bit / BYTE][g_decoded.bit % BYTE] = 1;
		g_decoded.bit++;
	}
	else if (signum == SIGUSR2)
	{
		g_decoded.buffer[g_decoded.bit / BYTE][g_decoded.bit % BYTE] = 0;
		g_decoded.bit++;
	}
}

static void	initialise(struct sigaction *sa)
{
	sa->sa_flags = 0;
	sigemptyset(&sa->sa_mask);
	sa->sa_sigaction = handler;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, sa, NULL);
	sigaction(SIGUSR2, sa, NULL);
	ft_bzero(&g_decoded, sizeof(t_decoded));
	g_decoded.string = (char *) malloc (sizeof (char));
	g_decoded.string[0] = '\0';
}

static int	receive_client(void)
{
	while (!g_decoded.finished)
	{
		if (g_decoded.to_send)
		{
			if (kill (g_decoded.sender, SIGUSR1))
				g_decoded.to_send = 0;
			else
				usleep(50);
		}
		if (g_decoded.bit == BUFFER * BYTE || find_null())
		{
			g_decoded.string = append_buffer(&g_decoded);
			if (!g_decoded.string)
				return (1);
			g_decoded.bit = 0;
		}
	}
	return (0);
}

int	main(void)
{
	struct sigaction	sa;

	initialise(&sa);
	while (1)
	{
		receive_client();
		while (!kill (g_decoded.sender, SIGUSR2))
			usleep(50);
		ft_printf("%s", g_decoded.string);
		free (g_decoded.string);
		ft_bzero(&g_decoded, sizeof(t_decoded));
		g_decoded.string = (char *) malloc (sizeof (char));
		g_decoded.string[0] = '\0';
	}
	free (g_decoded.string);
	return (0);
}
