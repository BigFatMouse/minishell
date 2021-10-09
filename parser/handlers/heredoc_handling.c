/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 00:15:12 by klanie            #+#    #+#             */
/*   Updated: 2021/08/05 03:11:06 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "terminal.h"

static void	rw_heredoc(t_heredoc *doc)
{
	char	*line;

	setup_heredoc_terminal();
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			printf("\033[A> ");
			break ;
		}
		if (!ft_strncmp(line, doc->stop_word, doc->stop_word_len + 1))
			break ;
		ft_putendl_fd(line, doc->fd);
		free(line);
	}
	if (line)
		free(line);
	exit(0);
}

static void	wait_heredoc(int *status, char *file, t_heredoc *d, t_command *cmd)
{
	t_simple_command	*c;

	wait(status);
	close(d->fd);
	if ((*status / 256) == 100)
	{
		unlink(file);
		cmd->is_sigint = 1;
		free(file);
	}
	else
	{
		c = cmd->commands[cmd->commands_num - 1];
		c->fd_in = open(file, O_RDONLY);
		if (c->fd_in < 0)
			c->err = 1;
		ft_lstadd_back(&cmd->heredocs, ft_lstnew(file));
		cmd->heredocs_num++;
	}
}

static char	*syntax_error_handling(char *s, t_command *cmd)
{
	if (*s == '|')
		printf("msh: syntax error near unexpected token `|'\n");
	else if (*s == '>' && *(s + 1) == '>')
		printf("msh: syntax error near unexpected token `>>'\n");
	else if (*s == '>')
		printf("msh: syntax error near unexpected token `>'\n");
	else if (*s == '<' && *(s + 1) == '<')
		printf("msh: syntax error near unexpected token `<<'\n");
	else if (*s == '<')
		printf("msh: syntax error near unexpected token `<'\n");
	else
		printf("msh: syntax error near unexpected token `newline'\n");
	cmd->data->errcode = 258;
	cmd->is_sigint = 1;
	return (s);
}

char	*heredoc_handling(char *s, t_command *cmd)
{
	t_heredoc			doc;
	pid_t				pid;
	char				*file;
	int					status;

	while (*s == ' ')
		s++;
	doc.stop_word = get_filename(&s, cmd->data);
	doc.stop_word_len = ft_strlen(doc.stop_word);
	if (!doc.stop_word || !*doc.stop_word)
	{
		free(doc.stop_word);
		return (syntax_error_handling(s, cmd));
	}
	file = get_heredoc_filename(cmd->heredocs_num + 1);
	doc.fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	signal(SIGINT, &sigint_nl_handler);
	pid = fork();
	if (pid == 0)
		rw_heredoc(&doc);
	else
		wait_heredoc(&status, file, &doc, cmd);
	free(doc.stop_word);
	return (s);
}
