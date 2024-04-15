/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:51:02 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/15 14:57:21 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "Libft/libft.h"

//Client
void	ft_send_int(int pid, int msg_len);
void	ft_send_signal(int pid, char msg);

//Server
int		ft_take_initial_len(int sign, int *flag);
void	ft_take_the_msg(int sign, char *str, int *flag);
void	ft_putnbr(int num);
void	ft_add_char(char *str, char c);
void	ft_decode(int sign);

//Utils
int		ft_free(char **str);

#endif