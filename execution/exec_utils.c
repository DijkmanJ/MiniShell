/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olehendrix <olehendrix@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:21 by ohendrix          #+#    #+#             */
/*   Updated: 2024/06/05 17:08:09 by olehendrix       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_openinfiles(t_command *command, t_list *current, int *fd)
{
	int	fd2;

	while (command->infiletracker < current->infileindex)
	{
		fd2 = open(command->infiles[command->infiletracker], O_RDONLY, 0777);
		command->infiletracker ++;
		if (fd2 == -1)
			ft_perror("FILE ERROR", command, 1);
		close(fd2);
	}
	if (command->failedfile && current->infileindex == -1)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_exit(command, "ERROR IN DUP2", 1);
		close(fd[0]);
		close(fd[1]);
	}
}

char	*ft_strnstr2(char *big, const char *little, size_t len, t_command *com)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big)
		ft_exit(com, "command not found", 1);
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	ft_waitpids(t_command *command)
{
	int	i;

	i = 0;
	while (i < command->cmd_tracker)
	{
		if (command->pids[i])
			waitpid(command->pids[i], &command->exitstatus, 0);
		i++;
	}
	if (WIFEXITED(command->exitstatus))
		command->exitstatus = WEXITSTATUS(command->exitstatus);
}

void	ft_restore_in_out(t_command *command)
{
	if (command->save_std_in > -1)
	{
		if (dup2(command->save_std_in, STDIN_FILENO) == -1)
			ft_exit(command, "ERROR IN DUP26", 1);
	}
	if (command->save_std_out > -1)
	{
		if (dup2(command->save_std_out, STDOUT_FILENO) == -1)
			ft_exit(command, "ERROR IN DUP27", 1);
	}
	close(command->save_std_in);
	close(command->save_std_out);
}

t_list	*getcommand_node(t_command *command)
{
	int		i;
	t_list	*current;

	i = 0;
	current = command->commands;
	while (i < command->cmd_tracker)
	{
		current = current->next;
		i ++;
	}
	return (current);
}
