/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:02:09 by klanie            #+#    #+#             */
/*   Updated: 2021/05/17 01:14:28 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static void	free_simple_commands(t_simple_command **cmds, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (cmds[i])
			free_simple_command(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_command(void *cmd)
{
	t_command	*c;

	c = (t_command *)cmd;
	if (!cmd)
		return ;
	if (c->commands && c->commands_num > 0)
		free_simple_commands(c->commands, c->commands_num);
	free(cmd);
}
