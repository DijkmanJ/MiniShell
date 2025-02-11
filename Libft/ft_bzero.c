/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:56:46 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 15:19:35 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

// int main (void)
// {
//     char a[] = "Hellodjndjdn";
//     char a2[] = "Hellodjndjdn";
//     ft_bzero(a, 5);
//     bzero(a2, 5);
//     printf("%s\n", a);
//     printf("%s\n", a2);
// }