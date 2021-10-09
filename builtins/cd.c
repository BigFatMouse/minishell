/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:26:59 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/06 16:39:32 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	cd_error(char *path)
{
	ft_putstr_fd("msh: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}

static void	set_pwd(char *old_pwd, char *new_pwd, t_data *data)
{
	export_env(old_pwd, data);
	export_env(new_pwd, data);
}

static int	change_dir(char *path, t_data *data)
{
	char	old_path[PATH_MAX];
	char	new_path[PATH_MAX];
	char	*new_pwd;
	char	*old_pwd;

	getcwd(old_path, PATH_MAX);
	if (chdir(path))
	{
		data->errcode = cd_error(path);
		return (1);
	}
	getcwd(new_path, PATH_MAX);
	old_pwd = get_env_value("PWD", data->env_list);
	if (!old_pwd)
		unset_one("OLDPWD", &data->env_list);
	else
	{
		free(old_pwd);
		old_pwd = ft_strjoin("OLDPWD=", old_path);
		new_pwd = ft_strjoin("PWD=", new_path);
		set_pwd(old_pwd, new_pwd, data);
		free(old_pwd);
		free(new_pwd);
	}
	return (0);
}

int	cd(char **cmd, t_data *data)
{
	char	*path;

	data->errcode = 0;
	if (!cmd[1] || cmd[1][0] == '#')
		path = get_env_value("HOME", data->env_list);
	else
		path = ft_strdup(cmd[1]);
	change_dir(path, data);
	free(path);
	return (data->errcode);
}
