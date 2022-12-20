/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:07:04 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/14 01:11:26 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* void	deliver_msg(int pid, const char *msg)
{
	int				i;
	int				n_bits;
	unsigned char	c;

	i = 0;
	while (msg[i] != '\0')
	{
		n_bits = 0;
		c = msg[i];
		while (n_bits < 8)
		{
			if ((c >> n_bits) & 0b00000001 == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			n_bits++;
		}
		i++;
	}
} */

/* void	send_success(int pid, char *nl)
{
	int	i;
	int	n_bits;

	i = 0;
	while (nl[i] != '\0')
	{
		n_bits = 0;
		while (n_bits < 8)
		{
			if ((nl[i] >> n_bits) & 0b00000001 == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
			n_bits++;
		}
		i++;
	}
} */

void	handle_sigusr(int sig)
{
	(void)sig;
}

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
