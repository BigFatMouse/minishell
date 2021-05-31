/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:00:00 by klanie            #+#    #+#             */
/*   Updated: 2021/05/10 17:46:53 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static void	copy_simple_commands(t_command *from, t_command *to, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		to->commands[i] = from->commands[i];
		i++;
	}
}

t_command	*expand_command(t_command *cmd)
{
	t_command	*new_cmd;

	new_cmd = NULL;
	new_cmd = new_command(cmd->available_commands_num + CMD_EXPAND_STEP);
	if (new_cmd)
	{
		new_cmd->commands_num = cmd->commands_num;
		copy_simple_commands(cmd, new_cmd, cmd->commands_num);
	}
	new_cmd->in_file = cmd->in_file;
	new_cmd->out_file = cmd->out_file;
	free(cmd->commands);
	free(cmd);
	return (new_cmd);
}
