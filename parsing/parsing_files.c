/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_files.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 15:54:07 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/05/31 17:55:27 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	addoutfile(t_command *command, char *str)
{
	char	**newarray;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (command->outfiles[count])
		count++;
	newarray = malloc((count + 2) * sizeof(char *));
	if (!newarray)
	{
		free(str);
		ft_mallocfail(command, "FAIL");
	}
	while (i < count)
	{
		newarray[i] = ft_safe_strdup(command->outfiles[i], command);
		i++;
	}
	newarray[i] = ft_safe_strdup(str, command);
	newarray[count + 1] = NULL;
	free_ptr_ptr(command->outfiles);
	command->outfiles = newarray;
	return (i);
}

void	addinfile(t_command *command, char *str)
{
	char	**newarray;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (command->infiles[count])
		count++;
	newarray = malloc((count + 2) * sizeof(char *));
	if (!newarray)
	{
		free(str);
		ft_mallocfail(command, "FAIL");
	}
	while (i < count)
	{
		newarray[i] = ft_safe_strdup(command->infiles[i], command);
		i++;
	}
	newarray[i] = ft_safe_strdup(str, command);
	newarray[count + 1] = NULL;
	free_ptr_ptr(command->infiles);
	command->infiles = newarray;
}

void	appendindex(int x, t_command *command)
{
	int	i;
	int	j;
	int	*outfappend;

	i = 0;
	j = 0;
	while (command->outfappend[i] != -1)
		i ++;
	outfappend = malloc((i + 2) * sizeof (int));
	if (!outfappend)
		ft_mallocfail(command, "FAIL");
	while (command->outfappend[j] != -1)
	{
		outfappend[j] = command->outfappend[j];
		j ++;
	}
	outfappend[j] = x;
	outfappend[j + 1] = -1;
	free(command->outfappend);
	command->outfappend = outfappend;
}

int	ft_set_files(t_command *command, char *str, int set)
{
	char	*newstr;

	newstr = ft_safe_strdup(str, command);
	newstr = adjustquotes(newstr);
	if (!newstr)
		ft_mallocfail(command, "MALLOCFAIL IN FT_SETFILES");
	if (set == 0)
	{
		addinfile(command, newstr);
		command->infilereset = false;
	}
	if (set == 1)
	{
		addoutfile(command, newstr);
		command->outfilereset = false;
	}
	if (set == 2)
	{
		appendindex(addoutfile(command, newstr), command);
		command->outfilereset = false;
	}
	return (free(newstr), 1);
}

void	init_files(t_command *command, char **tok)
{
	int	i;

	i = 0;
	while (tok[i] != NULL)
	{
		if (!ft_strncmp(tok[i], "<", 2))
			i += ft_set_files(command, tok[i + 1], 0) + 1;
		else if (!ft_strncmp(tok[i], ">", 2) && ft_strncmp(tok[i], ">>", 2))
			i += ft_set_files(command, tok[i + 1], 1) + 1;
		else if (tok[i][0] == '<' && tok[i][1] != '<')
			i += ft_set_files(command, &tok[i][1], 0);
		else if (tok[i][0] == '>' && tok[i][1] != '>')
			i += ft_set_files(command, &tok[i][1], 1);
		else if (!ft_strncmp(tok[i], ">>", 2) && tok[i][2] != '\0')
			i += ft_set_files(command, &tok[i][2], 2);
		else if (!ft_strncmp(tok[i], ">>", 3))
			i += ft_set_files(command, tok[i + 1], 2) + 1;
		else
			i = init_commands(command, command->tokens, i);
	}
	ft_files_to_com(command);
}
