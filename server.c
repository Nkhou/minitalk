/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:32:56 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/31 13:24:48 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	handler(int num, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static int				pid = 0;

	(void)context;
	if (pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		c = 0;
		i = 0;
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
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		ft_error();
	return (0);
}
