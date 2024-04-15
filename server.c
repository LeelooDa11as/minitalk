#include "minitalk.h"

int	ft_free(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
	return (1);
}

void	ft_add_char(char *str, char c)
{
	static int	i = 0;

	str[i] = c;
	i++;
	if (c == '\0')
		i = 0;
}


void ft_take_the_msg(int sign, char *str, int *flag)
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
		ft_add_char(str, c);
		if (c == '\0')
		{
			ft_putstr_fd(str, 1);
			ft_putstr_fd("\n", 1);
			*flag = 0;
			ft_free(&str);
		}
		bit = 0;
		c = '\0';
	}
}

int	ft_take_initial_len(int sign, int *flag)
{
	static int	bit = 0;
	static int	num	= 0;
	int 		aux;

	if (sign == SIGUSR1)
		num |= (0x01 << bit);

	bit++; 
	if (bit >= 32)
    {
		*flag = 1;
		bit = 0;
		aux = num;
		num = 0;
		return (aux);
	}
	return (-1);
}

void	ft_decode(int sign)
{
	static int 		flag = 0;
	static char		*str = NULL;
	int 			len;

	len = 0;

	if (flag == 0)
	{
		len = ft_take_initial_len(sign, &flag);
		if (len != -1)
		{
			printf("%d\n", len);
			str = malloc(sizeof(char) * (len + 1));
			if (!str)
				exit (0);
			ft_memset(str, '\0', len);
			str[len] = '\0';
		}
	}
	else if (flag == 1)
	{
		ft_take_the_msg(sign, str, &flag);
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
		usleep(100);
	return (0);
}