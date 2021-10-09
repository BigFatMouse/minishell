/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:46:34 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 00:52:48 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_unexpected(t_command *cmd, t_buffer *b)
{
	t_simple_command	*sc;

	sc = cmd->commands[cmd->commands_num - 1];
	if (sc->args_num < 1 && sc->fd_in == 0 && sc->fd_out == 1 \
		&& !*(b->content))
	{
		printf("msh: syntax error near unexpected token `|'\n");
		cmd->is_sigint = 1;
		cmd->data->errcode = 258;
		return (1);
	}
	return (0);
}

char	*pipe_handling(t_command **cmd, t_buffer **buf, char *s)
{
	t_simple_command	*sc;

	if (is_unexpected(*cmd, *buf))
		return (NULL);
	if ((*buf)->content && *(*buf)->content)
	{
		add_arg_to_command(cmd, (*buf)->content);
		free(*buf);
		*buf = new_buffer(START_BUFFER_SIZE);
		if (!*buf)
			return (NULL);
	}
	sc = new_simple_command(START_AVAILABLE_ARGS, (*cmd)->data, (void *)cmd);
	if (!sc)
		return (NULL);
	add_simple_cmd_to_command(cmd, sc);
	return (s + 1);
}
