/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:54:48 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/06 03:23:36 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	child_process(t_command *cmd, char **envp, t_data *data, int i)
{
	char	*cmd_path;

	if (cmd->commands[i]->fd_out > 1)
		change_fd(cmd->commands[i]->fd_out, 1);
	else if (i != (cmd->commands_num - 1))
		change_fd(data->fd[1], 1);
	close(data->fd[0]);
	if (*cmd->commands[i]->args[0] && is_builtin(cmd->commands[i]->args[0]))
	{
		exec_builtin(cmd->commands[i], data);
		exit(data->errcode);
	}
	else
	{
		cmd_path = check_cmd(cmd->commands[i]->args[0], data);
		if (!cmd_path || !*cmd->commands[i]->args[0])
			exit(pipes_error(cmd->commands[i]->args[0],
					"command not found", 127));
		execve(cmd_path, cmd->commands[i]->args, envp);
		exit(pipes_error(cmd_path, strerror(errno), 126));
	}
}

void	pipeline(t_command *cmd, char **envp, t_data *data, int fd_tmp)
{
	int	i;

	i = 0;
	while (i < cmd->commands_num)
	{
		if (cmd->commands[i]->fd_in > 0)
			change_fd(cmd->commands[i]->fd_in, 0);
		else if (i != 0)
			change_fd(fd_tmp, 0);
		if (pipe(data->fd) < 0)
			free_error(envp, data);
		if (!cmd->commands[i]->err)
		{
			data->pid[i] = fork();
			if (data->pid[i] < 0)
				free_error(envp, data);
			if (data->pid[i] == 0)
				child_process(cmd, envp, data, i);
		}
		close(data->fd[1]);
		fd_tmp = data->fd[0];
		i++;
	}
}

static void	close_fds(t_data *d)
{
	close(d->fd[0]);
	close(d->fd[1]);
}

void	pipes(t_command *cmd, t_data *data)
{
	char	**envp;
	int		fd0;
	int		fd_tmp;
	int		i;
	int		status;

	fd_tmp = 0;
	fd0 = dup(0);
	envp = list_to_arr(data);
	data->pid = malloc(sizeof(pid_t) * cmd->commands_num);
	pipeline(cmd, envp, data, fd_tmp);
	i = -1;
	while (++i < cmd->commands_num)
	{
		dup2(fd0, 0);
		close(fd0);
		close_fds(data);
		if (!cmd->commands[i]->err)
		{
			waitpid(data->pid[i], &status, 0);
			data->errcode = status / 256;
		}
	}
	free(data->pid);
	free_arr(&envp);
}
