/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 15:05:07 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:48:42 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// static char example_function(unsigned int index, char c)
// {
//     return c + index;
// }

// int main(void)
// {
//     char s[] = "abcdefg";
// 	// char s2[] = "abcdefg";
//     printf("%s\n", ft_strmapi(s, example_function));
//     // printf("%s\n", strmapi(s2, example_function));
// }