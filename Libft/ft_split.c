/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 14:57:11 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/04/23 14:20:35 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*ft_fillwords(char *dest, const char *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;

// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (j);
}

static char	*ft_subb(const char *s, int l)
{
	char	*result;
	int		i;

	result = malloc(l + 1);
	i = 0;
	if (!result)
	{
		return (NULL);
	}
	while (i < l && s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	free_result(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		k;

	count = ft_countwords(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		k = 0;
		while (s[k] != '\0' && s[k] != c)
			k++;
		result[i] = ft_subb(s, k);
		if (!result[i])
			return (free_result(result, i), NULL);
		s = s + k;
		i++;
	}
	result[count] = NULL;
	return (result);
}

// int main(void)
// {
//     char **splitted;
//     int i = 0;
//     char s[] = "Hello_World_How_Are_You";
//     char c = '_';
//     splitted = ft_split(s, c);
//     while (splitted[i])
//     {
//         printf("%s\n", splitted[i]);
//         i++;
//     }
// }
