/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:13:09 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/04 18:03:06 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	check_unset_arg(char *cmd, t_data *data)
{
	if (!ft_isalpha(cmd[0]))
	{
		ft_putstr_fd("msh: export: '", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd("': not a valid identifier", 2);
		data->errcode = 1;
		return (0);
	}
	else
		return (1);
}

static void	unset_first(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	ft_lstdelone(tmp, free);
}

void	unset_one(char *name_variable, t_list **list)
{
	t_list	*head;
	t_list	*tmp;
	char	*str1;

	head = *list;
	str1 = ft_strjoin(name_variable, "=");
	if (!ft_strncmp(head->content, str1, ft_strlen(str1)))
		unset_first(list);
	else
	{
		while (head->next)
		{
			if (!ft_strncmp(head->next->content, str1, ft_strlen(str1)))
			{
				tmp = head->next;
				head->next = head->next->next;
				ft_lstdelone(tmp, free);
			}
			if (head->next != NULL)
				head = head->next;
		}
	}
	free(str1);
}

int	unset(char **cmd, t_data *data)
{
	int	i;

	data->errcode = 0;
	i = 1;
	while (cmd[i])
	{
		if (check_unset_arg(cmd[i], data))
			unset_one(cmd[i], &data->env_list);
		i++;
	}
	return (0);
}
