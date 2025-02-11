/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 18:40:15 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/10 18:48:39 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printint2(int c)
{
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (c < 0)
	{
		write(1, "-", 1);
		c = c * -1;
	}
	if (c > 9)
		ft_printint2(c / 10);
	ft_printchar((c % 10) + 48);
}

int	ft_printint(int c)
{
	int	count;
	int	temp;

	count = 0;
	temp = c;
	if (c <= 0)
		count++;
	while (c != 0)
	{
		c = c / 10;
		count++;
	}
	ft_printint2(temp);
	return (count);
}
