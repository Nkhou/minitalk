/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:33:01 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/16 01:56:43 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;

	j = 0;
	if (argc == 3 && atoi(argv[1]) > 0)
	{
		while (argv[2][j])
		{
			i = 0;
			while (i < 8)
			{
				if (((argv[2][j] >> i) & 1) == 1)
					if (kill(atoi(argv[1]), SIGUSR1) == -1)
						return (1);
				else
					if (kill(atoi(argv[1]), SIGUSR2) == -1)
						return (1);
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
