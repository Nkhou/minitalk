/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:33:01 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/13 21:17:20 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	c;
	int		i;

	c = 'a';
	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 1)
			kill(atoi(argv[1]), SIGUSR1);
		else
			kill(atoi(argv[1]), SIGUSR2);
		i++;
		usleep(700);
	}
	return (0);
}
