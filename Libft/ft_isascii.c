/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:39:20 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/04 11:46:53 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int	main()
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isascii(i) != isascii(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isascii(i));
// 			printf("%i\n", isascii(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }