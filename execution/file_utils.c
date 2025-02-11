/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 15:45:44 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:27:20 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_configinput(int fd[2], t_command *command)
{
	int	check;

	check = config_infiles(command, true);
	if (check != 2)
	{
		if (check == 0 && !command->failedfile)
			return (0);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_exit(command, "ERROR IN DUP2", 1);
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}

int	ft_openinfile(t_command *command, t_list *current)
{
	current->infile_fd = open(command->infiles[current->infileindex],
			O_RDONLY, 0777);
	command->infiletracker ++;
	if (current->infile_fd == -1)
	{
		if (current->next && current->next->infileindex == -1)
			command->failedfile = true;
		else
			command->failedfile = false;
		return (ft_perror("FILE ERROR", command, 1), 0);
	}
	else if (dup2(current->infile_fd, STDIN_FILENO) == -1)
		return (ft_perror("ERROR IN DUP2", command, 1), 0);
	return (2);
}

int	config_infiles(t_command *command, bool next_cmd)
{
	t_list	*current;	
	int		*fd;

	fd = create_pipe(command);
	current = getcommand_node(command);
	if (!current && command->here_doc)
		return (free(fd), ft_onlydel(command));
	if (!current || (next_cmd && !current->next))
		return (free(fd), 1);
	if (command->cmd_count > 0 && next_cmd && current->next)
		current = current->next;
	if (current->cmd_delimiter)
	{
		if (ft_handledelimiter(command, current))
			return (free(fd), 0);
	}
	ft_openinfiles(command, current, fd);
	if (current->infileindex > -1)
		return (free(fd), ft_openinfile(command, current));
	return (free(fd), 1);
}

void	ft_outfilemode(t_command *command, t_list *current)
{
	int	i;

	i = 0;
	while (command->outfappend[i] != -1)
	{
		if (command->outfappend[i] == current->outfileindex)
		{
			current->outfile_fd = open(command->outfiles[current->outfileindex],
					O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (current->outfile_fd == -1)
				ft_perror("FILE ERROR", command, 1);
			break ;
		}
		i++;
	}
	if (command->outfappend[i] == -1)
	{
		current->outfile_fd = open(command->outfiles[current->outfileindex],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (current->outfile_fd == -1)
			ft_perror("FILE ERROR", command, 1);
	}
	if (dup2(current->outfile_fd, STDOUT_FILENO) == -1)
		ft_exit(command, "FAIL", 1);
}

int	config_outfiles(t_command *command)
{
	t_list	*current;
	int		fd2;

	current = getcommand_node(command);
	if (!current)
		return (0);
	while (command->outfiletracker < current->outfileindex)
	{
		fd2 = open(command->outfiles[command->outfiletracker],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd2 == -1)
			ft_perror("FILE ERROR2", command, 1);
		close(fd2);
		command->outfiletracker ++;
	}
	if (current->outfileindex > -1)
	{
		ft_outfilemode(command, current);
		command->outfiletracker ++;
		return (2);
	}
	return (1);
}
