/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:58:22 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/05 17:01:01 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (sign * result);
}

void	signal_recived(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("\x1b[32mSignal Recived\n");
}

void	send_bits(unsigned char c, int pid)
{
	int	i;
	int	send;

	i = 7;
	while (i > -1)
	{
		send = c >> i-- & 1;
		if (send)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(800);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR1, &signal_recived);
	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][0] == '0')
				exit(0);
			if (av[1][i] < '0' || av[1][i] > '9')
				return (ft_putstr("\033[1;33mError pid!!"), 0);
			i++;
		}
		pid = ft_atoi(av[1]);
		while (*av[2])
			send_bits(*av[2]++, pid);
		send_bits(*av[2], pid);
	}
	else
		ft_putstr("\033[0;31mArgument Error\n");
}
