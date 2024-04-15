/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:51:29 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/15 18:43:28 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_int_size(char *str)
{
	int	bsize;
	int	i;
	int	bytes;

	i = 0;
	bsize = 0;
	while (str[i])
	{
		if (str[i] | (1 << bsize))
			bsize += 1;
		if (bsize % 8 == 0)
			i++;
	}
	bytes = bsize / 8;
	return (bytes);
}

void	ft_send_signal(int pid, char msg)
{
	int				bit;
	unsigned char	c;

	bit = 0;
	while (bit < 8)
	{
		c = msg >> bit;
		if (c % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr_fd("Signal error\n", 1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("Signal error\n", 1);
		}
		usleep(80);
		bit++;
	}
}

void	ft_send_int(int pid, int msg_len)
{
	int				bit;
	int				c;

	bit = 0;
	while (bit < 32)
	{
		c = msg_len >> bit;
		if (c % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr_fd("Signal error\n", 1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("Signal error\n", 1);
		}
		usleep(80);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int			pid;
	int			i;
	const char	*message;

	if (argc != 3)
	{
		ft_putstr_fd("Error! s./client <PID> and the <message>\n", 1);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	message = argv[2];
	ft_send_int(pid, ft_int_size(argv[2]));
	usleep(100);
	while (message[i] != '\0')
	{
		ft_send_signal(pid, message[i]);
		i++;
	}
	ft_send_signal(pid, '\0');
	return (0);
}
