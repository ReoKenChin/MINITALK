/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:05:37 by mcherki           #+#    #+#             */
/*   Updated: 2022/03/05 17:08:21 by mcherki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	ft_pid(void);
void	signal_reciver(int sig, siginfo_t *sa, void *unused);
void	signal_recived(int sig);
void	send_bits(unsigned char c, int pid);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int num);

#endif
