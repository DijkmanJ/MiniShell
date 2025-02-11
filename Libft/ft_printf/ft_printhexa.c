/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhexa.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 18:36:49 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/10 18:47:16 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexalen(unsigned int c)
{
	int	count;

	count = 0;
	if (c <= 0)
		count++;
	while (c != 0)
	{
		c = c / 16;
		count++;
	}
	return (count);
}

void	ft_hexa(unsigned int c)
{
	char	*hex_digits;
	char	a;

	hex_digits = "0123456789abcdef";
	if (c >= 16)
	{
		ft_hexa(c / 16);
		ft_hexa(c % 16);
	}
	else
	{
		a = hex_digits[c];
		write(1, &a, 1);
	}
}

int	ft_printhexa(unsigned int c)
{
	unsigned int	temp;

	temp = c;
	ft_hexa(c);
	return (ft_hexalen(temp));
}

void	ft_hexa2(unsigned int c)
{
	char	*hex_digits;
	char	a;

	hex_digits = "0123456789ABCDEF";
	if (c >= 16)
	{
		ft_hexa2(c / 16);
		ft_hexa2(c % 16);
	}
	else
	{
		a = hex_digits[c];
		write(1, &a, 1);
	}
}

int	ft_printhexa2(unsigned int c)
{
	unsigned int	temp;

	temp = c;
	ft_hexa2(c);
	return (ft_hexalen(temp));
}
