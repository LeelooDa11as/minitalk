#include "minitalk.h"

int	ft_init_str(int len)
{
	if (!g_str)
	{
		g_str = malloc(sizeof(char) * (len + 1));
		printf("El len es de %d\n", len);
		if (!g_str)
			return (0);
		ft_memset(g_str, '\0', len);
		g_str[len] = '\0';
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


void ft_take_the_msg(int sign, int *flag)
{
	static int				bit = 0;
	static unsigned char	c = '\0';

	if (sign == SIGUSR1)
	{
		//printf("BIT is 1 \n");
		c |= (0x01 << bit);
	}
	//else
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
			*flag = 0;
			if (g_str)
				free(g_str);
			//g_str = NULL;
		}
		bit = 0;
		c = '\0';
	}
}

void	ft_take_initial_len(int sign, int *flag)
{
	static int	bit = 0;
	static int	num	= 0;

	if (sign == SIGUSR1)
	{
		//printf("BIT is 1 \n");
		num |= (0x01 << bit);
	}
	//else
		//printf("BIT is 0 \n");
	bit++; 
	if (bit >= 32)
    {
        printf("Received number: %d\n", num);
		*flag = 1;
		if (ft_init_str(num) == 0)
			exit(0);
		bit = 0;
		num = 0;
	}
}

void	ft_decode(int sign)
{
	static int flag = 0;

	if (flag == 0)
		ft_take_initial_len(sign, &flag);

	if (flag == 1)
		ft_take_the_msg(sign, &flag);
}

int	main(void)
{
	g_str = NULL;
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_decode);
	signal(SIGUSR2, ft_decode);
	while (1)
		pause();
	if (g_str)
		free(g_str);
	return (0);
}