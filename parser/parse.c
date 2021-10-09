/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:34 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 00:30:43 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static char	*symbol_handling(t_buffer **buf, t_command **cmd, char *s, \
							t_data *d)
{
	if (*s == ' ')
		s = space_handling(s, buf, cmd);
	else if (*s == '"')
		s = doublequote_handling(s, buf, cmd);
	else if (*s == '\'')
		s = quote_handling(s, buf, cmd);
	else if (*s == '|')
		s = pipe_handling(cmd, buf, s);
	else if (*s == '\\')
		s = backslash_handling(s, buf);
	else if (*s == '$')
		s = dollar_handling(s, buf, d);
	else if (*s == '<' || *s == '>')
		s = redirects_handling(s, *cmd);
	else
	{
		add_sym_to_buffer(buf, *s);
		s++;
	}
	return (s);
}

t_command	*parse(char *s, t_data *d)
{
	t_buffer	*buf;
	t_command	*cmd;
	char		*str;

	if (!s || !*s)
		return (NULL);
	str = s;
	cmd = new_command(START_CMD_NUM, d);
	add_simple_cmd_to_command(&cmd, \
							new_simple_command(START_AVAILABLE_ARGS, d, \
							(void *)cmd));
	buf = new_buffer(START_BUFFER_SIZE);
	while (!cmd->is_sigint && *str)
		str = symbol_handling(&buf, &cmd, str, d);
	if (buf->pos > 0)
		add_arg_to_command(&cmd, ft_strdup(buf->content));
	free_buffer(buf);
	buf = NULL;
	if (cmd->is_sigint)
	{
		free_command(cmd);
		cmd = NULL;
	}
	return (cmd);
}
