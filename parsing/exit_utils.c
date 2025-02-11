/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 16:37:48 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:59:38 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_mallocfail(t_command *command, char *str)
{
	perror(str);
	ft_free_struct(command);
	exit(1);
}

void	ft_exit(t_command *command, char *str, int exit_status)
{
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	ft_free_struct(command);
	exit(exit_status);
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = next;
	}
}

void	free_ptr_ptr(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i ++;
	}
	free(array);
}

void	ft_free_struct(t_command *command)
{
	if (command->commands)
		free_list(command->commands);
	if (command->tokens)
		free_ptr_ptr(command->tokens);
	if (command->infiles)
		free_ptr_ptr(command->infiles);
	if (command->outfiles)
		free_ptr_ptr(command->outfiles);
	if (command->line)
		free(command->line);
	if (command->pids)
		free(command->pids);
	if (command->outfappend)
		free(command->outfappend);
}
