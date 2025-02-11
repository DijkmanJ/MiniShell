/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: olehendrix <olehendrix@student.42.fr>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/30 10:59:39 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/06/06 15:20:03 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct g_sig	g_sighdlr;

void	init_g_sig(void)
{
	g_sighdlr.status = 0;
	g_sighdlr.exit_heredoc = false;
}

void	ctrl_c(void)
{
	if (g_sighdlr.status == 0)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_sighdlr.status == 1)
	{
		ft_putchar_fd('\n', 1);
		g_sighdlr.exit_heredoc = true;
		g_sighdlr.status = 0;
	}
	else if (g_sighdlr.status == 2)
	{
		ft_putchar_fd('\n', 1);
		rl_redisplay();
		rl_replace_line("", 0);
		g_sighdlr.status = 0;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGINT)
		ctrl_c();
	else if (sig == SIGQUIT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_sighdlr.status = 0;
	}
	else
	{
		ft_putstr_fd("Received unknown signal\n", 1);
		ft_putnbr_fd(getpid(), 1);
	}
	return ;
}

void	init_signals(int status)
{
	static struct sigaction	sa = {0};

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = 0;
	if (status == 0)
		init_g_sig();
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		return ;
	}
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		perror("sigterm");
		return ;
	}
	if (g_sighdlr.status != 2)
		signal(SIGQUIT, SIG_IGN);
	return ;
}
