#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
# include "Libft/libft.h"

//Client
void	ft_send_int(int pid, int msg_len);
void	ft_send_signal(int pid, char msg);

//Server
int	    ft_take_initial_len(int sign, int *flag);
void    ft_take_the_msg(int sign, char *str, int *flag);
void	ft_putnbr(int num);
int		ft_free(char **str);
void	ft_add_char(char *str, char c);
void	ft_decode(int sign);

#endif