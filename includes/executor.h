/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:19:04 by klanie            #+#    #+#             */
/*   Updated: 2021/08/05 17:21:53 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "command.h"
# include "libft.h"
# include "builtins.h"
# include "env.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>

char	**list_to_arr(t_data *data);
char	*check_cmd(char *cmd, t_data *data);
void	pipes(t_command *cmd, t_data *data);
void	exec_command(t_command *c, t_data *data);
void	exec_builtin(t_simple_command *command, t_data *data);
int		is_builtin(char *cmd);
int		free_arr(char ***arr);
int		pipes_error(char *cmd, char *err, int status);
int		free_error(char **envp, t_data *data);
void	change_fd(int fd1, int fd2);

#endif