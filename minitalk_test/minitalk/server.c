/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:41:29 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/11 19:45:01 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static int				bit_count;
	static unsigned char	c;

	(void)context;
	if (sig == SIGUSR2)
		c |= (0b00000001 << bit_count);
	bit_count++;
	if (bit_count > 7)
	{
		ft_printf("%c", c);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d", getpid());
	ft_printf("\n");
	while (1)
	{
		pause();
	}
	return (0);
}
