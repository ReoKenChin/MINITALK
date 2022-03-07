/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:01:28 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/05 17:04:14 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_pid(void)
{
	ft_putstr("\x1b[32mStarting server ...\n");
	sleep(1);
	ft_putstr("\x1b[32mProcess ID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sleep(1);
	ft_putstr("\033[1;33mWaiting for the client to print ...");
	ft_putstr("\033[0;40m\n");
}

void	signal_reciver(int sig, siginfo_t *sa, void *unused)
{
	static int	bit;
	static char	c;
	static int	pid_client;

	(void)unused;
	if (sa->si_pid != pid_client)
	{
		bit = 0;
		c = 0;
		pid_client = sa->si_pid;
	}
	c = c << 1 | (sig - 30);
	if (++bit < 8)
		return ;
	ft_putchar(c);
	bit = 0;
	c = 0;
}

int	main(void)
{
	struct sigaction	sa;

	ft_pid();
	sa.sa_sigaction = &signal_reciver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
