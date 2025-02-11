/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olehendrix <olehendrix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:28:20 by ohendrix          #+#    #+#             */
/*   Updated: 2024/06/05 12:17:20 by olehendrix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*adjuctquotes3(char *cmd, int delete, char *quotes, char *cmd2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)delete;
	while (cmd[i + j])
	{
		if (cmd[i + j] != quotes[0] && cmd[i + j] != quotes[1])
		{
			cmd2[i] = cmd[i + j];
			i++;
		}
		else
			j++;
	}
	return (free(quotes), free(cmd), cmd2);
}

char	*adjustquotes2(char *cmd, int delete, char *quotes)
{
	char	*cmd2;
	int		i;
	int		j;

	cmd2 = ft_calloc(sizeof(char), (ft_strlen(cmd) - delete) + 1);
	i = 0;
	j = 0;
	if (!cmd2)
		return (printf("MALLOC FAILED"), NULL);
	if (quotes[0] == quotes[1])
	{
		while (cmd[i + j])
		{
			if (cmd[i + j] != quotes[0])
			{
				cmd2[i] = cmd[i + j];
				i++;
			}
			else
				j++;
		}
	}
	else
		return (adjuctquotes3(cmd, delete, quotes, cmd2));
	return (free(quotes), free(cmd), cmd2);
}

char	*adjustquotes(char *cmd)
{
	char	*quotes;
	int		i;
	int		delete;

	i = -1;
	delete = 0;
	quotes = get_first_last_quote(cmd);
	if (quotes == NULL || !cmd)
		return (cmd);
	if (quotes[0] == quotes[1])
	{
		while (cmd[++ i] != '\0')
		{
			if (cmd[i] == quotes[0])
				delete ++;
		}
		return (adjustquotes2(cmd, delete, quotes));
	}
	while (cmd[++ i])
	{
		if (cmd[i] == quotes[0] || cmd[i] == quotes[1])
			delete ++;
	}
	return (adjustquotes2(cmd, delete, quotes));
}

char	*get_first_last_quote2(char *cmd, char *quotes)
{
	int	end;

	end = ft_strlen(cmd);
	while (end > 0)
	{
		if (cmd[end] == '\'' || cmd[end] == '\"')
		{
			quotes[1] = cmd[end];
			break ;
		}
		end --;
	}
	return (quotes);
}

char	*get_first_last_quote(char *cmd)
{
	char	*quotes;
	int		i;

	i = -1;
	quotes = ft_calloc (sizeof(char), 2);
	if (quotes == NULL)
		return (NULL);
	while (cmd[++ i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			quotes[0] = cmd[i];
			break ;
		}
	}
	if (quotes[0] == '\0')
		return (free(quotes), NULL);
	quotes = get_first_last_quote2(cmd, quotes);
	return (quotes);
}
