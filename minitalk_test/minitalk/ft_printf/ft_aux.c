/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:29:16 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/12 16:38:51 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_print_str(char *s, int fd, char c)
{
	int	i;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (c == 'd' || c == 'i' || c == 'u')
		free(s);
	return (i);
}

char	*ft_base(char r)
{
	char	*base;

	if (r == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base);
}
