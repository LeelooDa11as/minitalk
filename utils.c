#include "minitalk.h"

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 0 && num <= 9)
	{
		c = num + '0';
		write(1, &c, 1);
		return;
	}
	ft_putnbr(num / 10);
	ft_putnbr(num % 10);
}
