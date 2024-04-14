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
		usleep(42);
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
	g_len = ft_strlen(argv[2]);
	while (message[i] != '\0')
	{
		ft_send_signal(pid, message[i]);
		i++;
	}
	ft_send_signal(pid, '\0');
	return (0);
}