/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:33:01 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/20 11:33:19 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		d;

	j = 0;
	d = ft_atoi(argv[1]);
	if ((argc == 3) && (d > 0))
	{
		while (argv[2][j])
		{
			i = 0;
			while (i < 8)
			{
				if (((argv[2][j] >> i) & 1) == 1)
				{
					if (kill(d, SIGUSR1) == -1)
						return (1);
				}
				else
				{
					if (kill(d, SIGUSR2) == -1)
						return (1);
				}
				i++;
				usleep(700);
			}
			j++;
		}
	}
	else
		return (1);
	return (0);
}
