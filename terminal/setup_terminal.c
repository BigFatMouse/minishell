/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:52:08 by klanie            #+#    #+#             */
/*   Updated: 2021/08/03 02:02:00 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int	get_terminal_settings(struct termios *t)
{
	if (tcgetattr(0, t) != 0)
		return (1);
	return (0);
}

int	set_terminal_settings(struct termios *t)
{
	if (tcsetattr(0, TCSANOW, t) != 0)
		return (1);
	return (0);
}

int	setup_shell_terminal(void)
{
	struct termios	term;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sigint_shell_handler);
	if (tcgetattr(0, &term) != 0)
		return (1);
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		return (1);
	return (0);
}

int	setup_command_terminal(char *cmd)
{
	struct termios	term;

	if (cmd && ft_strlen(cmd) >= 11 && \
		!ft_strncmp(ft_strright(cmd, 11), "./minishell", 12))
	{
		signal(SIGINT, &sigint_empty_handler);
		signal(SIGQUIT, &sigquit_empty_handler);
	}
	else
	{
		signal(SIGINT, &sigint_nl_handler);
		signal(SIGQUIT, &sigquit_msg_handler);
	}
	if (tcgetattr(0, &term) != 0)
		return (1);
	term.c_lflag |= ECHOCTL;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		return (1);
	return (0);
}

int	setup_heredoc_terminal(void)
{
	struct termios	term;

	signal(SIGINT, &sigint_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
	if (tcgetattr(0, &term) != 0)
		return (1);
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		return (1);
	return (0);
}
