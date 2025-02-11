/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checksyntax.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/24 14:18:39 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/06 14:13:06 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	check_chars(char *line, char c)
{
	int	i;

	i = 1;
	while (line[i])
	{
		while (line[i] == ' ')
			i ++;
		if (line[i] == '\0' && i > 1)
			return (false);
		if (c == '|')
		{
			if (line[i] == '|'
				|| (line[i] == ' ' && line[i + 1] && line[i + 1] == '|'))
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	check_quotes(char *line)
{
	int		i;
	bool	d_o;
	bool	s_o;

	i = 0;
	s_o = false;
	d_o = false;
	if (line[i] == '|')
		return (false);
	while (line[i])
	{
		if ((line[i] == '>' || line[i] == '<' || line[i] == '|')
			&& !d_o && !s_o && check_chars(line + i, line[i]) == false)
			return (false);
		if (line[i] == '\"' && !s_o)
			d_o = !d_o;
		if (line[i] == '\'' && !d_o)
			s_o =! s_o;
		i ++;
	}
	if (d_o || s_o)
		return (false);
	return (true);
}

bool	checksyntax(char *line)
{
	bool	valid;

	valid = check_quotes(line);
	if (!ft_strncmp(line, "./minishell", 12))
		return (ft_putstr_fd("already in minishell ", 2), false);
	return (valid);
}
