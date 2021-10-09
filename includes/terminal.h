/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:26:18 by klanie            #+#    #+#             */
/*   Updated: 2021/07/30 16:50:09 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include <termios.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "libft.h"
# include "builtins.h"

void	rl_replace_line(const char *s, int n);

int		increment_shlvl(t_data *data);

void	sigquit_msg_handler(int signum);
void	sigquit_empty_handler(int signum);
void	sigint_shell_handler(int signum);
void	sigint_nl_handler(int signum);
void	sigint_heredoc_handler(int signum);
void	sigint_empty_handler(int signum);

int		get_terminal_settings(struct termios *t);
int		set_terminal_settings(struct termios *t);
int		setup_shell_terminal(void);
int		setup_command_terminal(char *cmd);
int		setup_heredoc_terminal(void);

char	*get_line(const char *prompt);

#endif