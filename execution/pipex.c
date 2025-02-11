/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 16:41:56 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 11:40:35 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_findpath(t_command *command, char *cmd, char **envp)
{
	char	**paths;
	char	*pathpart;
	char	*path;
	int		i;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (ft_strnstr2(envp[i], "PATH", 4, command) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		ft_mallocfail(command, "MALLOC FAILED IN FT_FINDPATH");
	i = -1;
	while (paths[++i])
	{
		pathpart = ft_strjoin2(command, paths[i], "/");
		if (!pathpart)
			ft_mallocfail(command, "MALLOC FAILED IN FT_STRJOIN");
		path = ft_safe_strjoin(command, pathpart, cmd);
		if (access(path, F_OK) == 0)
			return (free_ptr_ptr(paths), path);
		free(path);
	}
	return (free_ptr_ptr(paths), NULL);
}

void	ft_execute(t_command *command, char *cmd)
{
	char	**cmd_split;
	char	*path;

	cmd = adjustquotes(ft_safe_strdup(cmd, command));
	if (is_directory(cmd))
		ft_exit(command, "IS A DIRECTORY", 126);
	if (!cmd)
		return ;
	if (built_in(command, cmd) > 0)
		exit(EXIT_SUCCESS);
	cmd_split = ft_split(cmd, ' ');
	if (cmd_split == NULL)
		ft_mallocfail(command, "MALLOC FAILED IN SUPERSPLIT2");
	path = ft_findpath(command, cmd_split[0], command->envp);
	if (path == NULL)
	{
		free_ptr_ptr(cmd_split);
		ft_exit(command, "PATH NOT FOUND", 127);
	}
	if (execve(path, cmd_split, command->envp) == -1)
	{
		free(path);
		ft_exit(command, "ERROR IN EXECVE", 127);
	}
}

void	ft_childproces(int fd[2], t_command *command)
{
	int	check;

	init_signals(1);
	check = config_outfiles(command);
	if (check != 2 && command->cmd_tracker + 1 < command->cmd_count)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_exit(command, "ERROR IN DUP2", 1);
	}
	else if (command->cmd_count > 1 && command->cmd_count
		== command->cmd_tracker + 1 && check != 2)
		;
	else if ((command->cmd_tracker < command->cmd_count - 1
			|| command->cmd_tracker < command->pipes) && check != 2)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_exit(command, "ERROR IN DUP2", 1);
	}
	close(fd[0]);
	close(fd[1]);
	close(command->save_std_in);
	close(command->save_std_out);
	ft_execute(command, getcommand(command));
}

void	pipex2(t_command *command)
{
	int		*fd;
	pid_t	pid;

	while (command->cmd_tracker < command->cmd_count)
	{
		fd = create_pipe(command);
		g_sighdlr.status = 2;
		pid = ft_fork(command);
		if (!pid)
			ft_childproces(fd, command);
		else
		{
			if (!ft_configinput(fd, command))
				command->cmd_tracker ++;
			ft_updateout(command);
		}
		command->cmd_tracker ++;
		free(fd);
	}
}

void	pipex(t_command *command)
{
	command->save_std_in = dup(STDIN_FILENO);
	command->save_std_out = dup(STDOUT_FILENO);
	while (!config_infiles(command, false)
		&& command->cmd_tracker < command->cmd_count)
	{
		if (g_sighdlr.exit_heredoc == true)
			return ;
		command->cmd_tracker ++;
	}
	pipex2(command);
	ft_waitpids(command);
	openremainder(command);
	ft_restore_in_out(command);
	g_sighdlr.status = 0;
}
