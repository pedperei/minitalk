/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:02:08 by pedperei          #+#    #+#             */
/*   Updated: 2022/12/06 13:10:39 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define _POSIX_C_SOURCE 199309L

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
char	*ft_base(char r);
int		ft_print_char(char c, int fd);
int		ft_print_str(char *s, int fd, char c);
int		ft_putnbrhex_fd(unsigned int n, int fd, char r, int first);
char	*ft_itoa_u(unsigned int n);
int		ft_putnbrhex_ptr_fd(void *s, int fd, char *base, int first);
int		ft_select(char c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
#endif
