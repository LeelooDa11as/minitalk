#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
# include "Libft/libft.h"

static char	*g_str;
static int	g_len;

void	ft_send_signal(int pid, char msg);
void	ft_putnbr(int num);
int		ft_init_str(void);
void	ft_add_char(char c);
void	ft_decode(int sign);

#endif