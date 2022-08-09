/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:34:56 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/10 01:14:08 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <stdio.h>

int	g_action = 0;

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_action = 0;
	else if (signum == SIGUSR2)
		g_action = -1;
}

static int	send_byte(int pid, char letter)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < BYTE)
	{
		g_action = 1;
		if ((letter & (1 << i)))
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		if (err)
			return (-3);
		pause();
		if (g_action == -1 && letter != '\0')
			return (-4);
		i++;
	}	
	return (err);
}

static int	send_message(int pid, char **argv)
{
	int	i;
	int	err;
	int	len;

	i = 0;
	err = 0;
	len = ft_strlen(argv[2]);
	while (i <= len)
	{
		err = send_byte(pid, argv[2][i]);
		if (err)
			return (err);
		i++;
	}
	return (err);
}

static int	error_glossary(int err)
{
	if (err == -1)
		write(2, "Error! Improper input.\n", 23);
	else if (err == -2)
		write(2, "Error! Invalid PID.\n", 20);
	else if (err == -3)
		write(2, "Error! Failed communication.\n", 29);
	else if (err == -4)
		write(2, "Error! Failed malloc.\n", 22);
	return (err);
}

int	main(int argc, char **argv)
{
	int	j;
	int	pid;
	int	err;

	err = 0;
	if (argc != 3)
		return (error_glossary(-1));
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pid = ft_atoi(argv[1]);
	if (pid < 2)
		return (error_glossary(-2));
	err = send_message(pid, argv);
	if (err)
		return (error_glossary(err));
	pause();
	write(1, "Message delivered successfully!\n", 32);
	return (0);
}
