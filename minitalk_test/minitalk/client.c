/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:07:04 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/11 20:16:28 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>

void	deliver_msg(int pid, char *msg)
{
	int				i;
	int				n_bits;
	unsigned char	c;

	i = 0;
	while (msg[i] != '\0')
	{
		c = msg[i];
		n_bits = 0;
		while (n_bits < 8)
		{
			if ((c >> n_bits) & 0b00000001 == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(1000);
			n_bits++;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	deliver_msg(ft_atoi(argv[1]), argv[2]);
	deliver_msg(ft_atoi(argv[1]), "\n");
}