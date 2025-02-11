/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:09:42 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:16:04 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	return (src_len);
}

// int main(void)
// {
//     char src[] = "Hello";
//     char dest[] = "Whatsapp";

//     // char src2[] = "Hello";
//     // char dest2[] = "Whatsapp";

//     ft_strlcpy(dest, src, 2);
//     printf("%s", dest);

//     // strlcpy(dest2, src2, 8);
//     // printf("%s", dest2);
// }