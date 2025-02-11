/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:58:28 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 15:48:20 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	int		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (char *)src;
	while (n > 0)
	{
		cdest[i] = csrc[i];
		i++;
		n--;
	}
	return (dest);
}

// int main(void)
// {
//     // char src[] = "";
//     // char dest[50];

//     // char src2[] = "";
//     // char dest2[50];

//     memcpy(((void*)0), ((void*)0), 3);
//     // ft_memcpy(((void*)0), ((void*)0), 3);
//     // ft_memcpy(dest, src, strlen(src)+1);
//     // printf("%s\n", dest);

//     // memcpy(dest2, src2, strlen(src2)+1);
//     // printf("%s\n", dest2);
// }
