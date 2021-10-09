/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:52:21 by klanie            #+#    #+#             */
/*   Updated: 2021/08/03 00:02:07 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_command.h"

static void	copy_args(t_simple_command *from, t_simple_command *to,
								size_t args_num)
{
	size_t	i;

	i = 0;
	while (i < args_num)
	{
		to->args[i] = from->args[i];
		i++;
	}
}

t_simple_command	*expand_simple_command(t_simple_command *cmd)
{
	t_simple_command	*new_cmd;

	new_cmd = NULL;
	new_cmd = new_simple_command(cmd->available_args_num + \
									ARGS_EXPAND_STEP, cmd->data, cmd->parent);
	if (new_cmd)
	{
		new_cmd->args_num = cmd->args_num;
		copy_args(cmd, new_cmd, cmd->args_num);
		new_cmd->fd_in = cmd->fd_in;
		new_cmd->fd_out = cmd->fd_out;
	}
	free(cmd->args);
	free(cmd);
	return (new_cmd);
}
