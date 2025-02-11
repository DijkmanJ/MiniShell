/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 15:07:27 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/04/30 12:42:51 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstring(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (checkstring(s1[start], set) == 0)
	{
		start++;
	}
	return (start);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*string;
	int		start;
	int		i;
	int		end;

	start = ft_start(s1, set);
	end = ft_strlen(s1) - 1;
	while (end >= start && checkstring(s1[end], set) == 0)
	{
		end--;
	}
	string = malloc(sizeof(char) * (end - start + 2));
	if (!string)
	{
		return (NULL);
	}
	i = 0;
	while (start + i <= end)
	{
		string[i] = s1[start + i];
		i++;
	}
	free(s1);
	string[i] = '\0';
	return (string);
}

// int main(void)
// {
//     char s1[] = "#11#Hel1lo World1#1";
//     char set[] = "#1";
//     printf("%s\n", ft_strtrim(s1, set));
// }
