/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:20:43 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 13:01:50 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "env.h"

int	is_builtin(char *cmd)
{
	int	cmd_len;

	if (!cmd || !*cmd)
		return (0);
	cmd_len = ft_strlen(cmd) + 1;
	if (!ft_strncmp("cd", cmd, cmd_len)
		|| !ft_strncmp("echo", cmd, cmd_len)
		|| !ft_strncmp("env", cmd, cmd_len)
		|| !ft_strncmp("exit", cmd, cmd_len)
		|| !ft_strncmp("export", cmd, cmd_len)
		|| !ft_strncmp("pwd", cmd, cmd_len)
		|| !ft_strncmp("unset", cmd, cmd_len))
		return (1);
	return (0);
}

void	exec_builtin(t_simple_command *command, t_data *data)
{
	int		cmd_len;
	char	**cmd;

	cmd = command->args;
	cmd_len = ft_strlen(cmd[0]) + 1;
	if (!ft_strncmp("cd", cmd[0], cmd_len))
		cd(cmd, data);
	else if (!ft_strncmp("echo", cmd[0], cmd_len))
		echo(cmd, 1, data);
	else if (!ft_strncmp("env", cmd[0], cmd_len))
		env(cmd, data, 1);
	else if (!ft_strncmp("exit", cmd[0], cmd_len))
		exit_shell(cmd, data);
	else if (!ft_strncmp("export", cmd[0], cmd_len))
		export(cmd, data, 1);
	else if (!ft_strncmp("pwd", cmd[0], cmd_len))
		pwd(1, data);
	else if (!ft_strncmp("unset", cmd[0], cmd_len))
		unset(cmd, data);
}

static void	exec_one_builtin(t_simple_command *command, t_data *data)
{
	int		cmd_len;
	char	**cmd;

	cmd = command->args;
	cmd_len = ft_strlen(cmd[0]) + 1;
	if (!ft_strncmp("cd", cmd[0], cmd_len))
		cd(cmd, data);
	else if (!ft_strncmp("echo", cmd[0], cmd_len))
		echo(cmd, command->fd_out, data);
	else if (!ft_strncmp("env", cmd[0], cmd_len))
		env(cmd, data, command->fd_out);
	else if (!ft_strncmp("exit", cmd[0], cmd_len))
		exit_shell(cmd, data);
	else if (!ft_strncmp("export", cmd[0], cmd_len))
		export(cmd, data, command->fd_out);
	else if (!ft_strncmp("pwd", cmd[0], cmd_len))
		pwd(command->fd_out, data);
	else if (!ft_strncmp("unset", cmd[0], cmd_len))
		unset(cmd, data);
}

void	exec_command(t_command *c, t_data *data)
{
	if (c->commands_num == 1 && is_builtin(c->commands[0]->args[0]))
		exec_one_builtin(c->commands[0], data);
	else
		pipes(c, data);
}
