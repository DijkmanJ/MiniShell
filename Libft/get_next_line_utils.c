/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 15:01:13 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/05/21 16:26:55 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkbuffer(char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fillline(char *remainder)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!remainder || remainder[0] == '\0')
		return (NULL);
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(remainder), NULL);
	while (remainder[j] != '\n' && remainder[j] != '\0')
	{
		line[j] = remainder[j];
		j++;
	}
	if (remainder[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_cutremainder(char *remainder)
{
	int		j;
	int		k;
	char	*remainder2;

	j = 0;
	k = 0;
	if (!remainder)
		return (NULL);
	while (remainder[j] != '\n' && remainder[j] != '\0')
		j++;
	if (remainder[j] == '\0')
		return (free(remainder), NULL);
	j++;
	remainder2 = malloc(ft_strlen(remainder) - j + 1);
	if (!remainder2)
		return (free(remainder), NULL);
	while (remainder[j + k] != '\0')
	{
		remainder2[k] = remainder[j + k];
		k++;
	}
	remainder2[k] = '\0';
	free(remainder);
	return (remainder2);
}
