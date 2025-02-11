/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:36:00 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 15:20:42 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
	{
		return (8);
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
// 		if (ft_isalnum(i) != isalnum(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isalnum(i));
// 			printf("%i\n", isalnum(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
