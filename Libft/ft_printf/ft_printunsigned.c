/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printunsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 18:42:32 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/10 18:50:12 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printunsigned2(unsigned int c)
{
	if (c > 9)
		ft_printunsigned2(c / 10);
	ft_printchar((c % 10) + 48);
}

int	ft_printunsigned(unsigned int c)
{
	int				count;
	unsigned int	temp;

	count = 0;
	temp = c;
	if (temp == 0)
		count++;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	ft_printunsigned2(c);
	return (count);
}
