/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:33:01 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/26 16:52:47 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
void	action(int num)
{
	if (num == SIGUSR1)
		ft_putstr_fd("message recive\n", 1);
	else
		exit(1);
}

int	send_bit(char argv, int d)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((argv >> i) & 1) == 1)
		{
			if (kill(d, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(d, SIGUSR2) == -1)
				return (0);
		}
		i++;
		usleep(700);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	static int		j = 0;
	int				d;

	d = ft_atoi(argv[1]);
	if ((argc == 3) && (d > 0))
	{
		while (argv[2][j])
		{
			if (send_bit(argv[2][j], d) == 0)
				return (0);
			j++;
		}
		signal(SIGUSR1, action);
		if (send_bit('\0', d) == 0)
			return (0);
	}
	else
		return (1);
	return (0);
}
