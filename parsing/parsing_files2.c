/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_files2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 15:23:54 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/05/28 15:24:30 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_checkheredoc(t_command *command, t_list *current)
{
	if (command->here_doc)
	{
		current->cmd_delimiter = ft_safe_strdup(command->delimiter, command);
		current->cmd_delimiter = ft_strjoin(current->cmd_delimiter, "\n");
		if (!current->cmd_delimiter)
			ft_exit(command, "MALLOC ERROR IN STRJOIN", 0);
		command->here_doc = false;
		free(command->delimiter);
	}
}

void	ft_files_to_com2(t_command *command, t_list *current)
{
	int	i;

	i = 0;
	if (!command->outfilereset)
	{
		if (!command->outfiles[i])
			current->outfileindex = -1;
		else
		{
			while (command->outfiles[i] != NULL)
				i++;
			current->outfileindex = i - 1;
		}
	}
	current->filesset = true;
}

void	ft_files_to_com(t_command *command)
{
	t_list	*current;
	int		i;

	command->newcom = true;
	current = command->commands;
	if (!current)
		return ;
	i = 0;
	while (current->next != NULL)
		current = current->next;
	if (current->filesset)
		return ;
	ft_checkheredoc(command, current);
	if (!command->infilereset)
	{
		if (!command->infiles[i])
			current->infileindex = -1;
		else
		{
			while (command->infiles[i] != NULL)
				i++;
			current->infileindex = i - 1;
		}
	}
	ft_files_to_com2(command, current);
}
