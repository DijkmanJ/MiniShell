/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:15:30 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/05/31 17:57:59 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_command *command, char *cmd)
{
	(void)command;
	if (!ft_strncmp(cmd, "echo -n", 7) && cmd[7] == ' ')
	{
		ft_putstr_fd(cmd + 8, STDOUT_FILENO);
	}
	else if (!ft_strncmp(cmd, "echo -n", 8))
		return ;
	else if (!ft_strncmp(cmd, "echo", 4))
	{
		if (cmd[4] != ' ' && cmd[4] != '\0')
			return (ft_perror("no such file or directory", command, 1));
		ft_putstr_fd(cmd + 5, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}
