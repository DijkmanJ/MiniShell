/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_utils2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 14:21:41 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 15:19:44 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handledelimiter2(t_command *command, char *str, char *input)
{
	int		*fd;

	fd = create_pipe(command);
	g_sighdlr.status = 0;
	free(str);
	if (!g_sighdlr.exit_heredoc)
		write(fd[1], input, ft_strlen(input));
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_exit(command, "ERROR IN DUP2", 1);
	if (input)
		free(input);
	close(fd[0]);
	close(fd[1]);
	free(fd);
}

int	ft_onlydel(t_command *command)
{
	char	*input;
	char	*str;

	g_sighdlr.status = 1;
	input = NULL;
	command->delimiter = ft_strjoin(command->delimiter, "\n");
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(str, command->delimiter, ft_strlen(str)) || !str)
			break ;
		if (g_sighdlr.exit_heredoc == true)
		{
			g_sighdlr.status = 0;
			return (free(command->delimiter), free(input), 0);
		}
		input = ft_strjoin4(input, str);
	}
	ft_handledelimiter2(command, str, input);
	free(command->delimiter);
	command->delimiter = NULL;
	command->here_doc = false;
	g_sighdlr.exit_heredoc = false;
	return (1);
}

int	ft_handledelimiter(t_command *command, t_list *current)
{
	char	*input;
	char	*str;

	g_sighdlr.status = 1;
	input = NULL;
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str || !ft_strncmp(str, current->cmd_delimiter, ft_strlen(str)))
			break ;
		if (g_sighdlr.exit_heredoc == true)
		{
			g_sighdlr.status = 0;
			return (free(current->cmd_delimiter), free(input), 1);
		}
		input = ft_strjoin4(input, str);
	}
	ft_handledelimiter2(command, str, input);
	free(current->cmd_delimiter);
	current->cmd_delimiter = NULL;
	g_sighdlr.exit_heredoc = false;
	return (0);
}

void	openremainder(t_command *command)
{
	int	fd;

	if (g_sighdlr.exit_heredoc == true)
		return ;
	while (command->infiles[command->infiletracker] != NULL)
	{
		fd = open(command->infiles[command->infiletracker], O_RDONLY, 0777);
		if (fd == -1)
			ft_perror("FILE ERROR44", command, 1);
		close(fd);
		command->infiletracker ++;
	}
	while (command->outfiles[command->outfiletracker] != NULL)
	{
		fd = open(command->outfiles[command->outfiletracker],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			ft_perror("FILE ERROR", command, 1);
		command->outfiletracker ++;
	}
}

void	ft_updateout(t_command *command)
{
	t_list	*current;

	current = getcommand_node(command);
	if (!current)
		return ;
	while (command->outfiletracker < current->outfileindex)
		command->outfiletracker ++;
	if (current->outfileindex > -1)
		command->outfiletracker ++;
}
