/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 16:27:04 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:10:06 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_perror(char *err_msg, t_command *command, int exitstatus)
{
	command->exitstatus = exitstatus;
	ft_putstr_fd(err_msg, 2);
	ft_putchar_fd('\n', 2);
}

t_list	*createnode(t_command *command, int j)
{
	t_list	*lastnode;

	lastnode = malloc(sizeof(t_list));
	if (!lastnode)
		ft_mallocfail(command, "MALLOC FAIL");
	lastnode->str = ft_safe_strdup(command->tokens[j], command);
	lastnode->infileindex = -1;
	lastnode->outfileindex = -1;
	lastnode->infile_fd = -1;
	lastnode->outfile_fd = -1;
	lastnode->next = NULL;
	lastnode->filesset = false;
	lastnode->cmd_delimiter = NULL;
	return (lastnode);
}

t_list	*createnode2(t_command *command, char *str)
{
	t_list	*lastnode;

	lastnode = malloc(sizeof(t_list));
	if (!lastnode)
		ft_mallocfail(command, "MALLOC FAIL");
	lastnode->str = ft_safe_strdup(str, command);
	lastnode->infileindex = -1;
	lastnode->outfileindex = -1;
	lastnode->infile_fd = -1;
	lastnode->outfile_fd = -1;
	lastnode->next = NULL;
	lastnode->filesset = false;
	lastnode->cmd_delimiter = NULL;
	return (lastnode);
}

void	ft_checkflags(t_command *command, int j)
{
	t_list	*lastnode;

	if (command->tokens[j][0] == '\0')
		return ;
	if (command->commands == NULL)
	{
		lastnode = createnode(command, j);
		command->commands = lastnode;
		command->cmd_count ++;
		return ;
	}
	lastnode = command->commands;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->str = ft_strjoin(lastnode->str, " ");
	if (!lastnode->str)
		ft_mallocfail(command, "MALLOCFAIL");
	lastnode->str = ft_strjoin(lastnode->str, command->tokens[j]);
	if (!lastnode->str)
		ft_mallocfail(command, "MALLOCFAIL");
}
