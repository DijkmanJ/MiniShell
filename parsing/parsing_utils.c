/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olehendrix <olehendrix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:23:18 by ohendrix          #+#    #+#             */
/*   Updated: 2024/06/05 17:10:35 by olehendrix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printarray(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		printf("%s\n", list[i]);
		i++;
	}
	printf("\n");
}

void	printstruct(t_command *command)
{
	if (command->pipes)
		printf("pipe: %d\n", command->pipes);
	if (command->infiles[0] != NULL)
	{
		printf("infiles:\n");
		printarray(command->infiles);
	}
	if (command->outfiles[0] != NULL)
	{
		printf("outfiles:\n");
		printarray(command->outfiles);
	}
	if (command->here_doc)
		printf("here doc: true\n");
	if (command->commands)
	{
		printf("commands:\n");
		printstack(&command->commands);
	}
	if (command->cmd_count)
		printf("cmd_count: %d\n", command->cmd_count);
}

void	printstack(t_list **a)
{
	t_list	*begin;

	begin = *a;
	while (begin != NULL)
	{
		printf("%s\n", begin->str);
		if (begin->infileindex > -1)
			printf("infileindex: %d\n", begin->infileindex);
		if (begin->outfileindex > -1)
			printf("outfileindex: %d\n", begin->outfileindex);
		if (begin->cmd_delimiter)
			printf("del: %s\n", begin->cmd_delimiter);
		begin = begin->next;
	}
}

char	*ft_safe_strdup(char *str, t_command *command)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(str) + 1;
	dup = malloc(len);
	if (!dup)
		ft_mallocfail(command, "MALLOC fAILED IN STRDUP");
	ft_strlcpy(dup, str, len);
	return (dup);
}

char	*ft_safe_strjoin(t_command *command, char *s1, char const *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str == NULL)
		ft_mallocfail(command, "MALLOC FAILED IN STRDUP");
	return (str);
}
