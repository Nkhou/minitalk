/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:32:56 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/16 01:58:15 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void handler(int num, siginfo_t *siginfo, void *context)
{
	static char	c = 0;
	static int	i = 0;
	static int	pid = 0;

	(void)context;
	if (pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		i = 0;
		c = 0;
	}
	if (num == SIGUSR1)
		c = c + (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;

	pid = getpid();
	printf("%d\n",pid);
	struct sigaction	sa;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
