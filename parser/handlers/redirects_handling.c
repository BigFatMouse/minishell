/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:13:15 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 01:45:18 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "terminal.h"

static void	syntax_err_handling(char *s, t_simple_command *c)
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
	((t_command *)c->parent)->is_sigint = 1;
	c->data->errcode = 258;
}

static char	*out_handling(char *s, t_simple_command *c, int flags)
{
	char	*file;

	while (*s == ' ')
		s++;
	file = get_filename(&s, c->data);
	if (c->fd_out > 1)
		close(c->fd_out);
	if (file && *file)
		c->fd_out = open(file, flags, S_IREAD | S_IWRITE);
	else
		syntax_err_handling(s, c);
	if (c->fd_out < 0)
	{
		printf("msh: %s: %s\n", file, strerror(errno));
		c->err = 1;
		c->data->errcode = 1;
	}
	free(file);
	return (s);
}

static char	*in_handling(char *s, t_simple_command *c)
{
	char	*file;

	while (*s == ' ')
		s++;
	file = get_filename(&s, c->data);
	if (c->fd_in > 0)
		close(c->fd_in);
	if (file && *file)
		c->fd_in = open(file, O_RDONLY);
	else
		syntax_err_handling(s, c);
	if (c->fd_in < 0)
	{
		print_err(file, errno);
		c->err = 1;
		c->data->errcode = 1;
		while (*s && *s != '|')
			s++;
	}
	free(file);
	return (s);
}

char	*redirects_handling(char *s, t_command *c)
{
	t_simple_command	*sc;

	sc = c->commands[c->commands_num - 1];
	if (*s == '>' && *(s + 1) == '>')
		s = out_handling((s + 2), sc, O_WRONLY | O_APPEND | O_CREAT);
	else if (*s == '>')
		s = out_handling((s + 1), sc, O_WRONLY | O_TRUNC | O_CREAT);
	else if (*s == '<' && *(s + 1) == '<')
		s = heredoc_handling((s + 2), c);
	else
		s = in_handling((s + 1), sc);
	return (s);
}
