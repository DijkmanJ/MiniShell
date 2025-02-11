/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 15:02:39 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/05/28 15:38:06 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

int	ft_stritr(char *str, char *skipped)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (skipped[j])
		{
			if (str[i] == skipped[j])
				return (i);
			j ++;
		}
		i ++;
	}
	return (i);
}
