/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:34 by klanie            #+#    #+#             */
/*   Updated: 2021/05/30 14:53:07 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static char	*symbol_handling(t_buffer *buf, t_command *cmd, char *s, \
							t_list *env)
{
	if (*s == ' ')
		s = space_handling(s, &buf, cmd);
	else if (*s == '"')
		s = doublequote_handling(s, &buf);
	else if (*s == '\'')
		s = quote_handling(s, &buf);
	else if (*s == '|')
		s = pipe_handling(cmd, &buf, s);
	else if (*s == '\\')
		s = backslash_handling(s, &buf);
	else if (*s == '$')
		s = dollar_handling(s, &buf, env);
	else
	{
		add_sym_to_buffer(&buf, *s);
		s++;
	}
	return (s);
}

t_command	*parse(char **s, t_list *env)
{
	t_buffer	*buf;
	t_command	*cmd;

	cmd = new_command(START_CMD_NUM);
	add_simple_cmd_to_command(&cmd, new_simple_command(START_AVAILABLE_ARGS));
	buf = new_buffer(START_BUFFER_SIZE);
	while (**s && **s != ';')
		*s = symbol_handling(buf, cmd, *s, env);
	if (*buf->content)
		add_arg_to_command(cmd, buf->content);
	free(buf);
	if (**s == ';')
		*s = (*s + 1);
	return (cmd);
}
