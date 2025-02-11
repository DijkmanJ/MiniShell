/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 16:25:34 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:25:15 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char s1[] = "hellozbc";
//     char s2[] = "helloabc";
//     printf("%d\n", ft_strncmp(s1, s2, 7));
// 	printf("%d", strncmp(s1, s2, 7));
// }