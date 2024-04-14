#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
# include "Libft/libft.h"

static char	*g_str;

//Client
void	ft_send_int(int pid, int msg_len);
void	ft_send_signal(int pid, char msg);

//Server
void	    ft_take_initial_len(int sign, int *flag);
void    ft_take_the_msg(int sign, int *flag);
void	ft_putnbr(int num);
int		ft_init_str(int len);
void	ft_add_char(char c);
void	ft_decode(int sign);

#endif