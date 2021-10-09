/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:46:26 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/05 17:25:08 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_error(t_data *data)
{
	ft_putstr_fd("msh: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	data->errcode = 1;
	exit(1);
}

char	*get_env_value(char *name_variable, t_list *list)
{
	char	*str1;
	char	*res;

	res = NULL;
	str1 = ft_strjoin(name_variable, "=");
	while (list)
	{
		if (!ft_strncmp(list->content, str1, ft_strlen(str1)))
		{
			res = ft_strdup(list->content + ft_strlen(str1));
		}
		list = list->next;
	}
	free(str1);
	return (res);
}

char	*get_env_name(char *str)
{
	int		len;
	char	*res;

	len = 0;
	while (str[len] != '=')
	{
		if (str[len] == '\0')
			return (str);
		len++;
	}
	res = ft_substr(str, 0, len);
	return (res);
}

int	check_export_arg(char *cmd, t_data *data)
{
	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
	{
		ft_putstr_fd("msh: export: '", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		data->errcode = 1;
		return (0);
	}
	if (!ft_strrchr(cmd, '='))
		return (0);
	else
		return (1);
}
