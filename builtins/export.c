/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:15:30 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 12:12:50 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_envadd(t_command *command, char **envp, char *cmd)
{
	char	**envp2;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (envp[count])
		count++;
	envp2 = malloc((count + 2) * sizeof(char *));
	if (!envp2)
		ft_mallocfail(NULL, "Mallocfail");
	while (i < count)
	{
		envp2[i] = ft_safe_strdup(envp[i], command);
		i++;
	}
	envp2[i] = ft_safe_strdup(cmd, command);
	envp2[count + 1] = NULL;
	return (free_ptr_ptr(envp), envp2);
}

char	**ft_envdup(char **envp)
{
	char	**envp2;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (envp[count])
		count++;
	envp2 = malloc((count + 1) * sizeof(char *));
	if (!envp2)
		ft_mallocfail(NULL, "Mallocfail");
	while (i < count)
	{
		envp2[i] = ft_safe_strdup(envp[i], NULL);
		i++;
	}
	envp2[count] = NULL;
	return (envp2);
}

int	ft_getvar(char *cmd)
{
	int	i;

	i = 0;
	if (!ft_isalpha(cmd[0]))
		return (-1);
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '+' || cmd[i] == '-')
			return (-1);
		if (cmd[i] == '=')
			return (i + 1);
		i++;
	}
	return (i);
}

void	ft_export(t_command *command, char *cmd)
{
	int		variable;
	int		i;

	if (cmd[0] == '\0')
		return (ft_env(command, true));
	variable = ft_getvar(cmd);
	if (variable == -1 || !ft_strncmp(cmd, "=", 2))
		return (ft_perror("not a valid identifier", command, 1));
	i = 0;
	while (command->envp[i])
	{
		if (!ft_strncmp(command->envp[i], cmd, variable))
		{
			free(command->envp[i]);
			command->envp[i] = ft_safe_strdup(cmd, command);
			return ;
		}
		i++;
	}
	command->envp = ft_envadd(command, command->envp, cmd);
}
