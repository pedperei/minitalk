/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:25:46 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/30 15:10:00 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
			counter += ft_select(str[i++ + 1], args);
		else
		{
			if (str[i] != '%')
			{
				ft_putchar_fd(str[i], 1);
				counter++;
			}
			else
				counter = -1;
		}
		i++;
	}
	return (counter);
}

/* int main (void)
{
    int a;
    int b;
    long int c;
    long int d;
    void *asd;
    const char str[] = "asdsadff%";

    a = 0;
    b = 0;
    c = 8;
    d = 8;
    a = ft_printf(str);
    printf("\n");
    b = printf(str);
    printf("\n");
    printf("%d_%d", a, b); 
} */