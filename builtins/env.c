/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:58:24 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/02 19:58:25 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	env(char **cmd, t_data *data, int fd)
{
	t_list	*tmp;

	if (cmd[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		data->errcode = 127;
		return (127);
	}
	tmp = data->env_list;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, fd);
		tmp = tmp->next;
	}
	return (0);
}

void	copy_env(char **envp, t_list **head, t_data *data)
{
	t_list	*elem;
	char	*str;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		str = ft_strdup(envp[i]);
		elem = ft_lstnew(str);
		if (!elem)
			ft_error(data);
		ft_lstadd_back(head, elem);
		i++;
	}
}
