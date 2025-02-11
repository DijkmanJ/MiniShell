/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 14:15:30 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 12:14:59 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value(t_command *command, int index)
{
	int	i;

	i = 0;
	while (command->envp[index][i] != '=')
		i ++;
	return (command->envp[index] + i + 1);
}

int	get_index(t_command *command, int index)
{
	int	i;

	i = 0;
	while (command->envp[index][i] != '=')
		i ++;
	return (i);
}

char	*ft_getenv(t_command *command, char *variable)
{
	int	i;

	i = 0;
	while (command->envp[i])
	{
		if (!ft_strncmp(command->envp[i], variable, get_index(command, i)))
			return (get_value(command, i));
		i++;
	}
	return (NULL);
}

void	ft_env(t_command *command, bool declare)
{
	int		i;

	i = 0;
	while (command->envp[i])
	{
		if (declare)
			ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(command->envp[i], 1);
		ft_putchar_fd('\n', 1);
		i ++;
	}
}
