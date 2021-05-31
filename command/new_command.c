/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:58:10 by klanie            #+#    #+#             */
/*   Updated: 2021/05/10 17:47:48 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_command	*new_command(size_t scmd_num)
{
	t_command	*cmd;
	size_t		scmd_size;

	cmd = NULL;
	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	scmd_size = ((scmd_num + 1) * sizeof(t_simple_command *));
	cmd->commands_num = 0;
	cmd->available_commands_num = scmd_num;
	cmd->commands = (t_simple_command **)malloc(scmd_size);
	if (!cmd->commands)
	{
		free(cmd);
		return (NULL);
	}
	ft_memset(cmd->commands, 0, scmd_size);
	return (cmd);
}
