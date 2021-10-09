/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:59:22 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/05 20:08:17 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	print_echo(char **cmd, int fd, int flag)
{
	int		args;
	int		i;
	char	*str;

	args = 0;
	i = 1;
	while (cmd[args])
		args++;
	if (flag)
		i = flag;
	while (i < args - 1)
	{
		str = ft_strjoin(cmd[i], " ");
		ft_putstr_fd(str, fd);
		free(str);
		i++;
	}
	if (!flag)
		ft_putendl_fd(cmd[i], fd);
	else
		ft_putstr_fd(cmd[i], fd);
}

int	echo(char **cmd, int fd, t_data *data)
{
	char	*str;
	int		flag;
	int		i;

	data->errcode = 0;
	flag = 0;
	i = 1;
	if (!cmd[1])
	{
		str = ft_strdup("\n");
		ft_putstr_fd(str, fd);
		free(str);
		return (0);
	}
	if (!ft_strncmp("-n", cmd[i], strlen(cmd[i]) + 1))
		while (cmd[++i])
			if (ft_strncmp("-n", cmd[i], strlen(cmd[i]) + 1))
				break ;
	if (i > 1)
		flag = i;
	print_echo(cmd, fd, flag);
	return (0);
}
