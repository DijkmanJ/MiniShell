/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:17:36 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:05:28 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	checkpipe(char *line)
{
	int		i;
	bool	quotes;

	i = 0;
	quotes = false;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			quotes = !quotes;
		if (line[i] == '|' && !quotes)
			return (true);
		i ++;
	}
	return (false);
}

int	built_in_perm(t_command *command, char *line)
{
	char	*n_l;

	if (checkpipe(line))
		return (0);
	n_l = ft_safe_strdup(line, command);
	n_l = adjustquotes(n_l);
	if (!ft_strncmp(n_l, "exit", 5) || !ft_strncmp(n_l, "exit ", 5))
		return (ft_exit1(command, n_l), free(n_l), 1);
	if (!ft_strncmp(n_l, "cd", 2) && (n_l[2] == ' ' || n_l[2] == '\0'))
	{
		if (n_l[2] == '\0')
			return (ft_cd(command, NULL), free(n_l), 1);
		return (ft_cd(command, n_l + 3), free(n_l), 1);
	}
	if (!ft_strncmp(n_l, "export", 7))
		return (ft_export(command, n_l + 6), free(n_l), 1);
	if (!ft_strncmp(n_l, "export", 7) || !ft_strncmp(n_l, "export ", 7))
		return (ft_export(command, n_l + 7), free(n_l), 1);
	if (!ft_strncmp(n_l, "unset", 6))
		return (ft_unset(command, n_l + 5), free(n_l), 1);
	if (!ft_strncmp(n_l, "unset ", 6))
		return (ft_unset(command, n_l + 6), free(n_l), 1);
	return (free(n_l), 0);
}

int	built_in(t_command *command, char *cmd)
{
	if (!ft_strncmp(cmd, "exit", 5) || !ft_strncmp(cmd, "exit ", 5))
		return (ft_exit1(command, cmd), free(cmd), 1);
	if (!ft_strncmp(cmd, "echo", 4))
	{
		ft_echo(command, cmd);
		return (1);
	}
	else if (!ft_strncmp(cmd, "pwd", 3))
		return (ft_pwd(command), 1);
	else if (!ft_strncmp(cmd, "env", 3) && cmd[3] == '\0')
		return (ft_env(command, false), 1);
	return (0);
}
