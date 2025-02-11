/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 15:01:34 by ohendrix      #+#    #+#                 */
/*   Updated: 2023/11/01 16:07:41 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len);
	return (dup);
}

// int	main(void)
// {
// 	char original[] = "Whaddup";
// 	char *dup = ft_strdup(original);
// 	char *dup2 = strdup(original);
// 	printf("%s\n", dup);
// 	printf("%s", dup2);
// }
