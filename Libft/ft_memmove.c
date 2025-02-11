/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 14:39:29 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 15:49:44 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (char *)src;
	if (cdest < csrc)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
		return (dest);
	}
	while (n > 0)
	{
		cdest[n - 1] = csrc[n - 1];
		n--;
	}
	return (dest);
}

// int main(void)
// {
//     char source[100] = "abcdef";
// 	char source2[100] = "abcdef";

//     ft_memmove(source + 1, source, 3);
//     printf("%s\n", source);

//     memmove(source2 + 1, source2, 3);
//     printf("%s", source2);
// }