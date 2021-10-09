/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:08:43 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 01:35:01 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "executor.h"
#include "terminal.h"
#include "env.h"
#include <unistd.h>

static void	run_cmd(t_command *cmd, t_data *data)
{
	setup_command_terminal(cmd->commands[0]->args[0]);
	exec_command(cmd, data);
	free_command(cmd);
}

static int	run_minishell(t_data *data)
{
	t_command	*cmd;
	char		*str_cmd;

	while (1)
	{
		setup_shell_terminal();
		str_cmd = NULL;
		str_cmd = get_line("msh$ ");
		if (!str_cmd)
		{
			printf("\033[Amsh$ exit\n");
			return (data->errcode);
		}
		cmd = NULL;
		cmd = parse(str_cmd, data);
		if (cmd)
			run_cmd(cmd, data);
		if (str_cmd)
			free(str_cmd);
	}
	return (data->errcode);
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	term;
	t_data			*data;
	int				ret;

	(void) argc;
	(void) argv;
	data = malloc(sizeof(t_data));
	ft_memset(data, 0, sizeof(t_data));
	copy_env(envp, &data->env_list, data);
	increment_shlvl(data);
	get_terminal_settings(&term);
	ret = run_minishell(data);
	set_terminal_settings(&term);
	free(data);
	return (ret);
}
