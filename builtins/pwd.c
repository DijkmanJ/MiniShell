/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/24 14:18:01 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:37:06 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_command *command)
{
	char	*path;

	(void)command;
	path = NULL;
	path = ft_getenv(command, "PWD");
	if (path)
	{
		printf("%s\n", path);
	}
	else
		return (ft_perror("pwd Failed", command, 1));
}
