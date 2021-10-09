/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:46:09 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/04 13:53:54 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export(char **cmd, t_data *data, int fd)
{
	int	i;

	data->errcode = 0;
	if (!cmd[1])
	{
		export_sort(data, fd);
		return (0);
	}
	i = 1;
	while (cmd[i])
	{
		if (check_export_arg(cmd[i], data))
			export_env(cmd[i], data);
		i++;
	}
	return (0);
}

int	export_env(char *str, t_data *data)
{
	t_list	*elem;
	char	*str1;
	char	*name_variable;

	name_variable = get_env_name(str);
	str1 = ft_strjoin(name_variable, "=");
	free(name_variable);
	elem = data->env_list;
	while (elem)
	{
		if (!ft_strncmp(elem->content, str1, ft_strlen(str1)))
		{
			free(elem->content);
			elem->content = ft_strdup(str);
			free(str1);
			return (0);
		}
		elem = elem->next;
	}
	elem = ft_lstnew(ft_strdup(str));
	if (!elem)
		ft_error(data);
	ft_lstadd_back(&data->env_list, elem);
	free(str1);
	return (0);
}

static char	*add_prefix(char *str, t_data *data)
{
	char	*tmp;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strjoin("declare -x ", str);
	res = malloc(ft_strlen(tmp) + 3);
	if (!res)
		ft_error(data);
	while (tmp[i] != '=')
		res[j++] = tmp[i++];
	res[j] = tmp[i];
	res[++j] = 34;
	while (tmp[i] != '\0')
		res[++j] = tmp[++i];
	res[j] = 34;
	res[++j] = '\0';
	free(tmp);
	return (res);
}

static void	print_export_list(t_list *list, int fd, t_data *data)
{
	char	*str;

	while (list)
	{
		str = add_prefix(list->content, data);
		ft_putendl_fd(str, fd);
		free(str);
		list = list->next;
	}
}

void	export_sort(t_data *data, int fd)
{
	t_list	*elem;
	int		size;
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	size = ft_lstsize(data->env_list);
	while (++i < size - 1)
	{
		j = -1;
		elem = data->env_list;
		while (++j < size - 1)
		{	
			if (ft_strncmp(elem->content, elem->next->content,
					ft_strlen(elem->content)) > 0)
			{
				tmp = elem->content;
				elem->content = elem->next->content;
				elem->next->content = tmp;
			}
			elem = elem->next;
		}
	}
	print_export_list(data->env_list, fd, data);
}
