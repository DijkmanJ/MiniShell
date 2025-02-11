/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 16:11:20 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:39:28 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_abort(void)
{
	char	*substr;

	substr = malloc(1);
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		return (ft_abort());
	}
	if (start + len > ft_strlen(s))
		substr = malloc(ft_strlen(s) - start + 1);
	else
		substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int main(void)
// {
//     char s[] = "123456789";
//     char *substr1 = ft_substr(s, 5, 7);
// 	// char *substr2 = substr(s, 5, 7);

//     printf("%s\n", substr1);
// 	// printf("%s\n", substr2);
// }