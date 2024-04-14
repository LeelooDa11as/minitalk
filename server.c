#include "minitalk.h"

int	ft_init_str(void)
{
	if (!g_str)
		{
			g_str = malloc(sizeof(char) * g_len);
			if (!g_str)
				return (0);
			ft_memset(g_str, '0', g_len);
			g_str[g_len] = '\0';
		}
	return (1);
}

void	ft_add_char(char c)
{
	static int	i = 0;

	g_str[i] = c;
	i++;
	if (c == '\0')
		i = 0;
}

void	ft_decode(int sign)
{
	static int				bit = 0;
	static unsigned char	c = '\0';

	if (ft_init_str() == 0)
		exit(0);
	if (sign == SIGUSR1)
	{
		//printf("BIT is 1 \n");
		c |= (0x01 << bit);
	}
	else
		//printf("BIT is 0 \n");
	bit++; 
	if (bit >= 8)
	{
		//printf("%c\n", c);
		ft_add_char(c);
		if (c == '\0')
		{
			ft_putstr_fd(g_str, 1);
			ft_putstr_fd("\n", 1);
			free(g_str);
			g_str = NULL;
		}
		bit = 0;
		c = '\0';
	}
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_decode);
	signal(SIGUSR2, ft_decode);
	while (1)
		pause();
	return (0);
}