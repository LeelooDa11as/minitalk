#include "minitalk.h"

void	ft_send_signal(int pid, char msg)
{
	int				bit;
	unsigned char	c;

	bit = 0;
	while (bit < 8)
	{
		c = msg >> bit;
		if (c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
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
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}


int	main(int argc, char *argv[])
{
    int 		pid;
	int			i;
    const char  *message;


    if (argc != 3)
    {
        ft_putstr_fd("Error! s./client <PID> and the <message>\n", 1);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	message = argv[2];
	ft_send_int(pid, (int)ft_strlen(argv[2]));
	usleep(100);
	while (message[i] != '\0')
	{
		ft_send_signal(pid, message[i]);
		i++;
	}
	ft_send_signal(pid, '\0');
	return (0);
}