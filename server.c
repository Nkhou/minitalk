/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:32:56 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/11 22:41:00 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int num)
{
	char c;
	int i;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (SIGUSR1)
			c = c + (1 << i);
		i++;
	}
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = getpid();
	printf("%d\n",pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
