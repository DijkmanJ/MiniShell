/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:53:20 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 15:50:26 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

// int main (void)
// {
//     char test1[] = "123456789";
//     char test2[] = "123456789";

//     ft_memset(test1, 'A', 5);
//     memset(test2, 'A', 5);

//     printf("%s\n", test1);
//     printf("%s", test2);
// }