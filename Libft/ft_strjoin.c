/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olehendrix <olehendrix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:03:09 by ohendrix          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:01 by olehendrix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*snelle(char *string, char *s2, int i, int j)
{
	while (s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	free(s2);
	return (string);
}

char	*ft_strjoin4(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			string[i] = s1[i];
			i++;
		}
		free(s1);
	}
	return (snelle(string, s2, i, j));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	i = -1;
	j = -1;
	if (s1)
	{
		while (s1[++ i] != '\0')
			string[i] = s1[i];
	}
	while (s2[++ j] != '\0')
		string[i + j] = s2[j];
	string[i + j] = '\0';
	if (s1)
		free(s1);
	return (string);
}
