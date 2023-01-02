/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:41:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/02 00:01:26 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*Define two static vars:
bit_count -> number of bits to be shifted to the left
c -> char that is being sended through client 
(saves the bits that are being comunicated trough signals)
If signal is SIGUSR1 the bit will be 1 (|= operator and bit_count++)
If signal is SIGUSR2 the bit will be 0 (bit_count++ only)
When bit_count == 8 the byte has been fully comunicated
and it can be written to the terminal
SIGUSR1 signal is sended (kill function) to the client process to sinalize that
the process can continue because al the operations needed have been done.
usleep is used to garantee that the client process has already reached
the pause() function when the signal is sended through kill.*/
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
		c = 0b000000000;
		bit_count = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

/*Launches server printing server process id first.
Defines function handle_sigusr for the respective user defined signals:
SIGUSR1, SIGUSR2 (sa.sa_sigaction = handle_sigusr)
sa.sa_flags = SA_SIGINFO
"The signal handler takes three arguments, not one.  In
this case, sa_sigaction should be set instead of sa_handler.
This flag is meaningful only when establishing a signal handler."
If argc is not one print error and return 0*/
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
		return (0);
	}
	return (1);
}
