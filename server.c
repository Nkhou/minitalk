/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 07:32:56 by nkhoudro          #+#    #+#             */
/*   Updated: 2023/03/20 13:21:37 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
	(void)argc;
	(void)argv;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	struct sigaction	sa;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	// what's sigaction()?
	// sigaction() is a system call that allows us to specify a signal handler function for a particular signal.
	// what's signal()?
	// signal() is a system call that allows us to specify a signal handler function for a particular signal.
	// how we can use sigaction() to handle signals in a more flexible way than signal() does.
	// diffrence between signal() and sigaction() is that signal() is not reentrant, and sigaction() is.
	// signal() is not reentrant because it is not thread-safe.
	// signal() is less portable than sigaction() because it is not defined by the POSIX standard.
	// signal() is less powerful than sigaction() because it does not allow us to specify a signal mask that is used when the signal handler is executing.
	// signal() is less flexible than sigaction() because it allows us to specify a signal handler function that takes only one argument.
	// sigaction() is reentrant because it is thread-safe. why? because it is not reentrant because it is not thread-safe. what's thread-safe? it means that the function can be called from multiple threads without causing problems.
	// signal() is less flexible than sigaction() because it allows us to specify a signal handler function that takes only one argument.
	// sigaction() is reentrant because it is thread-safe.
	// sigaction() is more flexible than signal() because it allows us to specify a signal handler function that takes three arguments.
	// sigaction() is more portable than signal() because it is defined by the POSIX standard. what's POSIX standard? it's a standard for maintaining compatibility between operating systems.
	// sigaction() is more powerful than signal() because it allows us to specify a signal mask that is used when the signal handler is executing.what's signal mask? it's a set of signals that are blocked during the execution of the signal handler.
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
