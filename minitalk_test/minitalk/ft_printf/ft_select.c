/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:05:52 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/12 16:51:57 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = ft_print_char(va_arg(args, int), 1);
	else if (c == 's')
		counter = ft_print_str(va_arg(args, char *), 1, c);
	else if (c == 'p')
		counter = ft_putnbrhex_ptr_fd(va_arg(args, void *), 1, ft_base('r'), 0);
	else if (c == 'd')
		counter = ft_print_str(ft_itoa(va_arg(args, int)), 1, c);
	else if (c == 'i')
		counter = ft_print_str(ft_itoa(va_arg(args, int)), 1, c);
	else if (c == 'u')
		counter = ft_print_str(ft_itoa_u(va_arg(args, unsigned int)), 1, c);
	else if (c == 'x' || c == 'X')
		counter = ft_putnbrhex_fd(va_arg(args, unsigned int), 1, c, 0);
	else if (c == '%')
		counter = ft_print_char('%', 1);
	else
		counter = 0;
	return (counter);
}
