/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:24:05 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:48:15 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	k;
	int	nb;

	i = 0;
	k = 0;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			k++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	if (k == 1)
		nb = -nb;
	return (nb);
}

// int main(void)
// {
//     char nptr[] = "    -1234ab33";
//     printf("%d\n", ft_atoi(nptr));
//     printf("%d", atoi(nptr));
// }