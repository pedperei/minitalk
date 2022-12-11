/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:53:22 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/11 19:58:40 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nil(unsigned long long n, int fd)
{
	if (n == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	return (0);
}

int	ft_write_zerox(int fd, int counter)
{
	write(fd, "0x", 2);
	return (counter + 2);
}

int	ft_putnbrhex_ptr_fd(void *ptr, int fd, char *base, int first)
{
	int					temp;
	unsigned long long	n;
	static int			counter;

	if (first == 0)
	{
		first = 1;
		counter = 0;
	}
	n = (unsigned long long)ptr;
	if (ptr == NULL && counter == 0)
		return (ft_print_nil(n, 1));
	if (counter == 0)
		counter = ft_write_zerox(fd, counter);
	temp = n;
	if (n != 0)
	{
		ft_putnbrhex_ptr_fd((void *)(n / 16), fd, base, first);
		temp = n % 16;
		write(fd, &base[temp], 1);
		counter++;
	}
	return (counter);
}
