/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:31:30 by klanie            #+#    #+#             */
/*   Updated: 2021/05/17 03:05:51 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	*new_parser(void)
{
	t_parser			*p;
	t_simple_command	*sc;
	t_command			*cmd;

	p = NULL;
	p = (t_parser *)malloc(sizeof(t_parser));
	if (!p)
		return (NULL);
	ft_memset(p, 0, sizeof(t_parser));
	p->buf = new_buffer(START_BUFFER_SIZE);
	sc = NULL;
	sc = new_simple_command(START_AVAILABLE_ARGS);
	cmd = new_command(START_CMD_NUM);
	add_simple_cmd_to_command(&cmd, sc);
	p->commands = ft_lstnew(cmd);
	p->current_command = p->commands;
	if (!p->buf || !p->commands)
	{
		free_parser(p);
		return (NULL);
	}
	return (p);
}
