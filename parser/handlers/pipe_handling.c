/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:46:34 by klanie            #+#    #+#             */
/*   Updated: 2021/05/29 22:37:30 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*pipe_handling(t_command *cmd, t_buffer **buf, char *s)
{
	t_simple_command	*sc;

	if ((*buf)->content)
	{
		add_arg_to_command(cmd, (*buf)->content);
		free(*buf);
		*buf = new_buffer(START_BUFFER_SIZE);
		if (!*buf)
			return (NULL);
	}
	sc = new_simple_command(START_AVAILABLE_ARGS);
	if (!sc)
		return (NULL);
	add_simple_cmd_to_command(&cmd, sc);
	return (s + 1);
}
