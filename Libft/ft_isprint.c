/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:49:27 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/10/25 14:49:57 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c != 127 && c <= 127)
	{
		return (16384);
	}
	else
	{
		return (0);
	}
}

// #include <stdio.h>
// #include <ctype.h>

// int	main()
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isprint(i) != isprint(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isprint(i));
// 			printf("%i\n", isprint(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }