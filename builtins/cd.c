/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:15:30 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:46:21 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd2(t_command *command, char *oldpath)
{
	int	i;

	i = 0;
	while (command->envp[i] != NULL)
	{
		if (!ft_strncmp(command->envp[i], "PWD=", 4))
		{
			free(command->envp[i]);
			command->envp[i] = ft_strjoin3("PWD=", getcwd(NULL, 0));
			if (!command->envp[i])
				ft_mallocfail(command, "MALLOCFAIL");
		}
		else if (!ft_strncmp(command->envp[i], "OLDPWD=", 7) && oldpath)
		{
			free(command->envp[i]);
			command->envp[i] = ft_strjoin3("OLDPWD=",
					ft_safe_strdup(oldpath, command));
			if (!command->envp[i])
				ft_mallocfail(command, "MALLOCFAIL");
		}
		i++;
	}
}

void	ft_cd(t_command *command, char *cmd)
{
	char	*oldpath;

	oldpath = ft_getenv(command, "PWD");
	if (oldpath == NULL)
	{
		cmd = ft_getenv(command, "OLDPWD");
		if (!cmd)
			return (ft_perror("directory not found", command, 1));
	}
	if (!cmd)
		cmd = ft_getenv(command, "HOME");
	if (ft_countwords(cmd, ' ') > 1)
		return (ft_perror("too many arguments", command, 1));
	else if (cmd[0] == '~' && cmd[1] == '\0')
		cmd = ft_getenv(command, "HOME");
	else if (!ft_strncmp(cmd, "-", 2))
		cmd = ft_getenv(command, "OLDPWD");
	if (!cmd)
		return (ft_perror("env path not found", command, 1));
	if (chdir(cmd) == -1)
		return (ft_perror("no such file or directory", command, 1));
	ft_cd2(command, oldpath);
}
