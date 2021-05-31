/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:20:43 by klanie            #+#    #+#             */
/*   Updated: 2021/05/30 15:38:12 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	is_builtin(char *cmd)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd) + 1;
	if (!ft_strncmp("cd", cmd, cmd_len)
		|| !ft_strncmp("env", cmd, cmd_len)
		|| !ft_strncmp("export", cmd, cmd_len)
		|| !ft_strncmp("pwd", cmd, cmd_len)
		|| !ft_strncmp("unset", cmd, cmd_len))
		return (1);
	return (0);
}

static void	exec_builtin(char **cmd, t_list *env_list)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd[0]) + 1;
	if (!ft_strncmp("cd", cmd[0], cmd_len))
		cd(cmd[1], env_list);
	else if (!ft_strncmp("env", cmd[0], cmd_len))
		env(env_list);
	else if (!ft_strncmp("export", cmd[0], cmd_len))
		export(cmd[1], env_list);
	else if (!ft_strncmp("pwd", cmd[0], cmd_len))
		pwd();
	else if (!ft_strncmp("unset", cmd[0], cmd_len))
		unset(cmd[1], &env_list);
}

void	exec_command(t_command *c, t_list *env_list)
{
	char	**cmd;

	cmd = c->commands[0]->args;
	if (is_builtin(cmd[0]))
		exec_builtin(cmd, env_list);
}
