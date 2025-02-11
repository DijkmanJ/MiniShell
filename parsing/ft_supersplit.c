/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_supersplit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/24 13:27:01 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/06/04 11:45:47 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_countwords(char *s, char c)
{
	int		i;
	int		j;
	bool	d_inquotes;
	bool	s_inquotes;

	i = 0;
	j = 0;
	d_inquotes = false;
	s_inquotes = false;
	while (s[i] != '\0')
	{
		while (s[i] == c && (!d_inquotes || !s_inquotes))
			i++;
		if (s[i] != '\0' || s[i] == '\"' || s[i] == '\'')
			j++;
		while ((s[i] != '\0' && (s[i] != c)) || (d_inquotes || s_inquotes))
		{
			if (s[i] == '\"' && !s_inquotes)
				d_inquotes = !d_inquotes;
			if (s[i] == '\'' && !d_inquotes)
				s_inquotes = !s_inquotes;
			i++;
		}
	}
	return (j);
}

void	ft_fill(char *s, char **result, int k, int j)
{
	int	i;

	i = 0;
	result[j - 1] = malloc(k + 1);
	if (!result[j - 1])
		return ;
	while (i < k && s[i] != '\0')
	{
		result[j -1][i] = s[i];
		i++;
	}
	result[j - 1][i] = '\0';
}

void	ft_suballoc(char *s, char c, char **result, t_split split)
{
	while (s[split.i] != '\0')
	{
		while (s[split.i] == c && (!split.d_inquotes || !split.s_inquotes))
			split.i++;
		if (s[split.i] != '\0' || s[split.i] == '\"' || s[split.i] == '\'')
		{
			split.j++;
			split.k = 0;
		}
		while ((s[split.i] != '\0' && (s[split.i] != c))
			|| (split.d_inquotes || split.s_inquotes))
		{
			if (s[split.i] == '\"' && !split.s_inquotes)
				split.d_inquotes = !split.d_inquotes;
			if (s[split.i] == '\'' && !split.d_inquotes)
				split.s_inquotes = !split.s_inquotes;
			split.k++;
			split.i++;
		}
		ft_fill(s + (split.i - split.k), result, split.k, split.j);
	}
}

void	ft_supersplit(char *s, char c, t_command *command)
{
	t_split	split;
	int		wordcount;

	split = (t_split){0, 0, 0, false, false};
	wordcount = ft_countwords(s, c);
	command->tokens = malloc(sizeof(char *) * (wordcount + 1));
	command->tokens[wordcount] = NULL;
	ft_suballoc(s, c, command->tokens, split);
}
