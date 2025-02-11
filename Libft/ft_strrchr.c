/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:52:31 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/03 11:33:46 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last_occurence;

	last_occurence = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			last_occurence = &s[i];
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return ((char *)(last_occurence));
}

// int	main(void)
// {
// 	char s[] = "Hallo, ik ben een clown";
// 	char c = 'l';

// 	char *ptr = ft_strrchr(s, c);
// 	char *ptr2 = strrchr(s, c);
// 	if (ptr != NULL && ptr2 != NULL)
// 	{
// 		printf("%ld\n", ptr - s);
// 		printf("%ld", ptr2 - s);
// 	}
// 	else
// 		printf("Karakter niet gevonden");
// }
