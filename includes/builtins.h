/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:33:47 by klanie            #+#    #+#             */
/*   Updated: 2021/08/04 18:03:30 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "env.h"
# define PATH_MAX 4096 

void	copy_env(char **envp, t_list **list, t_data *data);
int		echo(char **cmd, int fd, t_data *data);
int		env(char **cmd, t_data *data, int fd);
int		exit_shell(char **cmd, t_data *data);
int		export(char **cmd, t_data *data, int fd);
int		export_env(char *str, t_data *data);
void	export_sort(t_data *data, int fd);
void	unset_one(char *name_variable, t_list **list);
int		unset(char **cmd, t_data *data);
char	*get_env_value(char *name_variable, t_list *list);
char	*get_env_name(char *str);
int		check_export_arg(char *cmd, t_data *data);
int		cd(char **cmd, t_data *data);
int		pwd(int fd, t_data *data);
void	ft_error(t_data *data);

#endif