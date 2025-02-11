/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 14:10:54 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/05/27 16:12:30 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str(char *str, int neg, int a, int i)
{
	int	len;

	len = i;
	while (i > 0)
	{
		if (neg > 0)
			str[0] = '-';
		str[i + neg - 1] = a % 10 + '0';
		a = a / 10;
		i--;
	}
	str[len + neg] = '\0';
	return (str);
}

static int	ft_icount(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		a;
	int		neg;
	char	*str;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		neg++;
		n = -n;
	}
	a = n;
	i = ft_icount(n);
	str = (char *)malloc((i + neg + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_str(str, neg, a, i);
	return (str);
}
