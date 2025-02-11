/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 16:24:09 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 13:58:20 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_struct(t_command *command)
{
	command->infiles = malloc(sizeof (char *));
	if (!command->infiles)
		ft_mallocfail(command, "FAIL");
	command->infiles[0] = NULL;
	command->infiletracker = 0;
	command->outfiletracker = 0;
	command->outfiles = malloc(sizeof (char *));
	if (!command->outfiles)
		ft_mallocfail(command, "FAIL");
	command->outfappend = malloc(sizeof (int));
	if (!command->outfappend)
		ft_mallocfail(command, "FAIL");
	command->outfappend[0] = -1;
	command->outfiles[0] = NULL;
	init_struct2(command);
}

void	init_struct2(t_command *command)
{
	command->save_std_in = -1;
	command->save_std_out = -1;
	command->commands = NULL;
	command->here_doc = false;
	command->delimiter = NULL;
	command->cmd_count = 0;
	command->cmd_tracker = 0;
	command->pipes = 0;
	command->newcom = false;
	command->infilereset = false;
	command->outfilereset = false;
	command->tokens = NULL;
	command->pids = NULL;
	command->value = NULL;
	command->failedfile = false;
}

int	pipescommand(char *str, t_command *command)
{
	char	**array;
	int		i;
	t_list	*newnode;
	t_list	*lastnode;

	i = 0;
	if (!ft_strchr(str, '|'))
		return (0);
	array = ft_split(str, '|');
	while (array[i])
	{
		newnode = createnode2(command, array[i]);
		if (command->commands == NULL)
			command->commands = newnode;
		else
		{
			lastnode = command->commands;
			while (lastnode->next != NULL)
				lastnode = lastnode->next;
			lastnode->next = newnode;
		}
		command->cmd_count ++;
		i++;
	}
	return (free_ptr_ptr(array), 1);
}

void	addcommand(t_command *command, int j)
{
	t_list	*newnode;
	t_list	*lastnode;

	if (!ft_strchr(command->tokens[j], '\'')
		&& !ft_strchr(command->tokens[j], '\"'))
		if (pipescommand(command->tokens[j], command))
			return ;
	if (!command->newcom || command->tokens[j][0] == '\0')
		return (ft_checkflags(command, j));
	newnode = createnode(command, j);
	command->cmd_count ++;
	if (command->commands == NULL)
	{
		command->commands = newnode;
		return ;
	}
	lastnode = command->commands;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	lastnode->next = newnode;
	command->newcom = false;
}
