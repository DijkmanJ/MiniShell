/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:30:42 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/10/25 14:33:24 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (2048);
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
// 		if (ft_isdigit(i) != isdigit(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isdigit(i));
// 			printf("%i\n", isdigit(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }