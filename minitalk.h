/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:51:02 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/15 18:06:44 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "Libft/libft.h"

void	ft_send_int(int pid, int msg_len);
void	ft_send_signal(int pid, char msg);
int		ft_take_initial_len(int sign, int *flag);
void	ft_take_the_msg(int sign, char *str, int *flag);
void	ft_add_char(char *str, char c);
void	ft_decode(int sign);
int		ft_free(char **str);
int		ft_int_size(char *str);

#endif