/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 18:41:04 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/13 13:46:36 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_ptrlen(unsigned long long addr)
{
	int	count;

	count = 0;
	while (addr != 0)
	{
		addr = addr / 16;
		count++;
	}
	return (count);
}

void	ft_printptr2(unsigned long long addr)
{
	char	*hex_digits;
	char	c;

	hex_digits = "0123456789abcdef";
	if (addr >= 16)
	{
		ft_printptr2(addr / 16);
		ft_printptr2(addr % 16);
	}
	else
	{
		c = hex_digits[addr];
		write(1, &c, 1);
	}
}

int	ft_printptr(void *ptr)
{
	int					count;
	unsigned long long	addr;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long long)ptr;
	write (1, "0x", 2);
	ft_printptr2(addr);
	count = 2 + ft_ptrlen(addr);
	return (count);
}
