/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:25:05 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:14:28 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		i++;
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
	{
		dst[i] = '\0';
	}
	return (k);
}

// int main(void)
// {
//     char dst[14] = "a";
//     // char dst2[14] = "a";

//     ft_strlcat(dst, "lorem ipsum dolor sit amet", 4);
//     printf("%s\n", dst);

//     // strlcat(dst2, "lorem ipsum dolor sit amet", 0);
//     // printf("%s\n", dst2);
// }