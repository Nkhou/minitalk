/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:32:56 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/28 22:11:35 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_handle(unsigned char c, siginfo_t *siginfo_t)
{
	static int			pid;
	t_unicode static	unicode;

	if (pid != siginfo_t->si_pid)
	{
		pid = siginfo_t->si_pid;
		unicode.bytenum = 0;
		unicode.i = 0;
		ft_bzero(unicode.p, 4);
	}
	if (c >= 192 && c <= 223)
		unicode.bytenum = 2;
	else if (c >= 224 && c <= 239)
		unicode.bytenum = 3;
	else if (c >= 240 && c <= 255)
		unicode.bytenum = 4;
	unicode.p[unicode.i++] = c;
	if (unicode.i == unicode.bytenum)
	{
		write(1, unicode.p, unicode.i);
		unicode.bytenum = 0;
		unicode.i = 0;
		ft_bzero(unicode.p, 4);
	}
}

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
		if ((c >= 0) && (c < 128))
			write(1, &c, 1);
		else
			ft_handle(c, siginfo);
		if (c == 0)
			kill(siginfo->si_pid, SIGUSR1);
		c = 0;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argc;
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
