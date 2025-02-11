/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 15:09:44 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/04 11:25:32 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_append(t_command *command, char *line, int i, int j)
{
	char	*newtoken;
	int		k;

	newtoken = ft_calloc(sizeof(char), ft_strlen(line)
			+ ft_strlen(command->value) - j + 2);
	if (newtoken == NULL)
		ft_mallocfail(command, "MALLOC FAILED IN APPEND");
	k = 0;
	while (k < i - 1)
	{
		newtoken[k] = line[k];
		k++;
	}
	if (command->value)
	{
		newtoken = ft_safe_strjoin(command, newtoken, command->value);
		if (command->infilereset)
			free(command->value);
		command->infilereset = false;
	}
	newtoken = ft_safe_strjoin(command, newtoken, line + (i + j));
	free(line);
	return (newtoken);
}

char	*ft_expandvariable(t_command *command, char *line, int i)
{
	char	*variable;
	int		j;

	j = 0;
	if (line[i] == '?')
	{
		j = 1;
		command->value = ft_itoa(command->exitstatus);
		command->infilereset = true;
	}
	else
	{
		j = ft_stritr(line + i + j, " $\'\"\0");
		if (j == 0)
			return (line);
		variable = ft_substr(line, i, j);
		if (!variable)
			ft_mallocfail(command, "FAIL");
		command->value = ft_getenv(command, variable);
		free(variable);
	}
	return (ft_append(command, line, i, j));
}

char	*ft_variable(t_command *command, char *line)
{
	int		i;
	int		inquotes;

	i = 0;
	inquotes = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'')
			inquotes = !inquotes;
		if (line[i] == '$' && !inquotes && line[i + 1] != ' '
			&& line[i + 1] != '\0' && line[i + 1] != '\"')
		{
			line = ft_expandvariable(command, line, i + 1);
			if (line[0] == '\0')
				break ;
			i = -1;
		}
		i++;
	}
	return (line);
}
