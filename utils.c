/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:50:44 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/15 14:52:17 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_free(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
	return (1);
}
/*void	ft_putnbr(int num)
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
}*/
