/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 01:10:45 by klanie            #+#    #+#             */
/*   Updated: 2021/07/29 01:16:14 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	sigint_empty_handler(int signum)
{
	(void) signum;
}

void	sigint_heredoc_handler(int signum)
{
	(void) signum;
	exit(100);
}

void	sigint_nl_handler(int signum)
{
	(void) signum;
	write(1, "\n", 1);
}

void	sigint_shell_handler(int signum)
{
	(void) signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
