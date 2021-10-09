/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd_to_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:19:58 by klanie            #+#    #+#             */
/*   Updated: 2021/05/10 19:46:55 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "simple_command.h"

void	add_simple_cmd_to_command(t_command **cmd, t_simple_command *scmd)
{
	if ((*cmd)->available_commands_num < ((*cmd)->commands_num + 1))
		*cmd = expand_command(*cmd);
	(*cmd)->commands[(*cmd)->commands_num] = scmd;
	(*cmd)->commands_num++;
}
