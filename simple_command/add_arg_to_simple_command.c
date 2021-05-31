/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_to_simple_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:17:15 by klanie            #+#    #+#             */
/*   Updated: 2021/05/10 19:50:22 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_command.h"

void	add_arg_to_simple_command(t_simple_command **cmd, char *arg)
{
	if ((*cmd)->available_args_num < ((*cmd)->args_num + 1))
		*cmd = expand_simple_command(*cmd);
	(*cmd)->args[(*cmd)->args_num] = arg;
	(*cmd)->args_num++;
}
