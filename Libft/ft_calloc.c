/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 15:17:21 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:48:23 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

// int	main(void)
// {
// 	int j = 5;
// 	int i = 0;
// 	int *a = (int*)calloc(j, sizeof(int));
// 	while (i < j)
// 	{
// 		printf("%d", a[i]);
// 		i++;
// 	}
// 	printf("%s", "\n");
// 	i = 0;
// 	int *b = (int*)ft_calloc(j, sizeof(int));
// 	while (i < j)
// 	{
// 		printf("%d", b[i]);
// 		i++;
// 	}
// }
