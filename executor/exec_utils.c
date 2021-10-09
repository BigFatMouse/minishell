/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:54:45 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/03 16:23:13 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	free_arr(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	return (0);
}

static int	path_error(char *cmd, t_data *data)
{
	ft_putstr_fd("msh: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	data->errcode = 127;
	exit(127);
}

static char	**add_path(char *cmd, t_data *data)
{
	char	**path;
	char	*str1;
	char	*tmp;
	char	*path_env;
	int		i;

	i = -1;
	path_env = get_env_value("PATH", data->env_list);
	if (!path_env)
		path_error(cmd, data);
	path = (ft_split(path_env, ':'));
	free(path_env);
	while (path[++i])
	{
		tmp = path[i];
		str1 = ft_strjoin("/", cmd);
		if (!str1)
			ft_error(data);
		path[i] = ft_strjoin(path[i], str1);
		if (!path[i])
			ft_error(data);
		free(str1);
		free(tmp);
	}
	return (path);
}

char	*check_cmd(char *cmd, t_data *data)
{
	char		**path;
	int			i;
	char		*ret;
	struct stat	buf;
	int			result;

	i = -1;
	result = stat(cmd, &buf);
	if (result == 0 && buf.st_mode & S_IEXEC)
		return (cmd);
	path = add_path(cmd, data);
	while (path[++i])
	{	
		result = stat(path[i], &buf);
		if (result == 0)
		{
			ret = ft_strdup(path[i]);
			free_arr(&path);
			if (!ret)
				ft_error(data);
			return (ret);
		}
	}
	free_arr(&path);
	return (NULL);
}

char	**list_to_arr(t_data *data)
{
	char	**env;
	int		i;
	t_list	*list;

	list = data->env_list;
	i = 0;
	env = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	while (list)
	{
		env[i] = ft_strdup(list->content);
		if (!env[i])
			ft_error(data);
		list = list->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}
