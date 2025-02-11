/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 14:40:35 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:57:25 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit2(t_command *command, char **array, int i)
{
	while (array[1][i] != '\0')
	{
		if (!ft_isdigit(array[1][i]))
		{
			free_ptr_ptr(array);
			ft_exit(command, "No numeric value", 2);
		}
		i++;
	}
	if (array[1][0] == '\0')
		ft_exit(command, "No numeric value", 255);
	ft_free_struct(command);
	if (array[1][0] == '+')
		exit(atoi(&array[1][1]));
	exit(atoi(array[1]));
}

void	ft_exit1(t_command *command, char *line)
{
	char	**array;
	int		i;

	i = 0;
	free(command->line);
	command->line = ft_safe_strdup(line, command);
	free(line);
	if (!ft_strncmp(command->line, "exit", 5)
		|| !ft_strncmp(command->line, "exit ", 6))
	{
		printf("exit\n");
		ft_exit(command, NULL, command->exitstatus);
	}
	array = ft_split(command->line, ' ');
	if (!array)
		ft_mallocfail(command, "MALLOC FAIL");
	printf("exit\n");
	if (array[2])
		ft_exit(command, "To many arguments", 1);
	array[1] = ft_strtrim(array[1], "\"");
	if (array[1][0] == '+')
		i ++;
	if (array[1][0] == '-')
		ft_exit(command, "", 255 + ft_atoi(array[1]) + 1);
	ft_exit2(command, array, i);
}
