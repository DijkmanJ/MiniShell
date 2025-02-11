/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 14:27:30 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:09:04 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(t_command *command, char *mode)
{
	while (1)
	{
		command->line = readline("minishell: ");
		if (!command->line)
		{
			free_ptr_ptr(command->envp);
			exit(EXIT_SUCCESS);
		}
		if (command->line[0] != '\0')
		{
			command->line = ft_strtrim(command->line, " \t");
			add_history(command->line);
			if (!checksyntax(command->line))
			{
				ft_perror("Wrong syntax", command, 2);
				free(command->line);
			}
			else
				fill_struct(command, mode);
		}
		else
			free(command->line);
	}
	free(command->line);
	ft_free_struct(command);
}

int	main(int argc, char **argv, char **envp)
{
	t_command	command;

	command.envp = ft_envdup(envp);
	command.exitstatus = 0;
	init_signals(0);
	if (!envp || argc < 1)
		return (1);
	parse_input(&command, argv[1]);
}
