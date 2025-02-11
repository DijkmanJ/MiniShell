/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 16:27:35 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 15:46:37 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;
	size_t	i;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
		{
			return ((unsigned char)cs1[i] - (unsigned char)cs2[i]);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char s1[] = "abcdef";
//     char s2[] = "abcdme";
//     printf("%d\n", ft_memcmp(s1, s2, 5));
// 	printf("%d", memcmp(s1, s2, 5));
// }