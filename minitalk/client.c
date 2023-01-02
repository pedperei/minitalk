/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:07:04 by pedperei          #+#    #+#             */
/*   Updated: 2023/01/02 00:03:01 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig)
{
	(void)sig;
}

/*handler function is defined (that does nothing) to the SIGUSR1 signal,
when the SIGUSR1 signal is received from server process the client is unpaused.
If argc is 3 (server PID,message) message will be sent to the server process:
The msg is passed char by char and each char(1byte 8bits) is passed bit by bit.
The 8 bits from each char will be passed from right to left using >> operator:
if the reusult from & operator is 1 SIGUSR1 is sended to server
if the reusult from & operator is 0 SIGUSR2 is sended to server
the process is paused for each bit that is being comunicated
and is unpaused when this bit has been treated by server handle_sigusr function
and the SIGUSR1 is sended to the client*/
int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;
	int					n_bits;

	i = -1;
	sa.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa, 0);
	if (argc == 3)
	{
		while (argv[2][++i] != '\0')
		{
			n_bits = 0;
			while (n_bits < 8)
			{
				if ((argv[2][i] >> n_bits) & 0b00000001 == 1)
					kill(ft_atoi(argv[1]), SIGUSR1);
				else
					kill(ft_atoi(argv[1]), SIGUSR2);
				pause();
				n_bits++;
			}
		}
	}
	return (0);
}
