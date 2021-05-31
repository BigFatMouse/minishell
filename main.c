/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:08:43 by klanie            #+#    #+#             */
/*   Updated: 2021/05/30 15:35:26 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "executor.h"

int	main(int argc, char **argv, char **envp)
{
	t_list		*env_list;
	t_command	*cmd;
	char		*str_cmd;

	(void) argc;
	(void) argv;
	env_list = NULL;
	copy_env(envp, &env_list);
	str_cmd = ft_strdup("export test=test; env");
	while (*str_cmd)
	{
		cmd = parse(&str_cmd, env_list);
		exec_command(cmd, env_list);
	}
}
