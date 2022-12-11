/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:27:26 by pedperei          #+#    #+#             */
/*   Updated: 2022/11/30 14:12:13 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Se numero for negativo ou 0 converte para positivo e i incrementa 1 
(para dar espaço ao sinal ou ao nº no caso do 0)*/
/*Vai dividindo o nº original por 10 de forma a contar os digitos*/
int	count_digit(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/*poe os numeros no array do fim para o inicio completando com o null
i = 1 para nao considerar o caracter do sinal que ja foi definido
se se tratar do min_int anda-se um byte para a frente
para por o null pq o ultimo numero ja foi posto na funcao ft_itoa*/
char	*fill_array_str(char *str_nbr, int len, int n, int flag)
{
	int	i;

	i = 1;
	if (n == 0)
		str_nbr[0] = (n % 10) + '0';
	while (n > 0)
	{
		str_nbr[len - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (flag == 1)
		len++;
	str_nbr[len] = '\0';
	return (str_nbr);
}

/*memoria alocada para a string a contar com o espaço do sinal(se houver) 
e do null terminator*/
/*se nº for negativo converte para positivo e poe na 1ª posicao 
da string um sinal -*/
/*excepcao min INT*/
/*sinal - na primeira posicao*/
/*ultimo numero na ultima posicao da string*/
/*atualiza o numero sem o ultimo digito e sem o sinal*/
/*atualiza a variavel de comprimento do numero*/
/*sinal - na primeira posicao*/
/*atualiza o numero sem o sinal*/
/*(na variavel len o sinal e considerado)*/
char	*ft_itoa(int n)
{
	char	*str_nbr;
	int		len;
	int		flag;

	len = count_digit(n);
	str_nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str_nbr))
		return (NULL);
	flag = 0;
	if (n < 0)
	{
		str_nbr[0] = '-';
		if (n == -2147483648)
		{
			str_nbr[len - 1] = '8';
			n = 214748364;
			len = len - 1;
			flag = 1;
		}
		else
			n = -n;
	}
	return (fill_array_str(str_nbr, len, n, flag));
}
