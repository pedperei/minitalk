/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:41:29 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/14 01:18:40 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static int				bit_count;
	static unsigned char	c;

	(void)context;
	usleep(200);
	if (sig == SIGUSR1)
		c |= (0b00000001 << bit_count);
	bit_count++;
	if (bit_count > 7)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_sigaction = handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	if (argc == 1)
	{
		ft_putstr_fd("Server PID:", 1);
		ft_putnbr_fd(getpid(), 1);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}
