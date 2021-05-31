/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_to_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:53:24 by klanie            #+#    #+#             */
/*   Updated: 2021/05/17 02:55:37 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	add_arg_to_command(t_command *cmd, char *arg)
{
	add_arg_to_simple_command(&cmd->commands[cmd->commands_num - 1], arg);
}
