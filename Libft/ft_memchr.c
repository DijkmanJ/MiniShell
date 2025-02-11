/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 16:26:25 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:48:07 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cs;

	cs = (char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (char)c)
		{
			return (&cs[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char s[] = "abcdef";
// 	char *ptr;
// 	char *ptr2;
//     ptr = ft_memchr(s, 'c', 5);
// 	ptr2 = memchr(s, 'c', 5);
// 	if (ptr != NULL)
// 	{
// 		printf("%ld\n", ptr - s);
// 	}
// 	else
// 	{
// 		printf("Karakter niet gevonden!\n");
// 	}
// 	if (ptr2 != NULL)
// 	{
// 		printf("%ld", ptr2 - s);
// 	}
// 	else
// 	{
// 		printf("Karakter niet gevonden!");
// 	}
// }