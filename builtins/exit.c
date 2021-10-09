/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:13:27 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/05 17:45:39 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <limits.h>

static int	check_long(char *str, int minus)
{
	int					i;
	unsigned long long	num;

	num = 0;
	i = 0;
	if (minus)
		i++;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (num - 1 > LLONG_MAX || (num > LLONG_MAX && !minus))
			return (0);
		i++;
	}
	return (1);
}

static int	is_num(char *str)
{
	int					i;
	int					minus;

	i = 0;
	minus = 0;
	if (str[0] == '-' && str[1])
	{
		minus = 1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			puts("!");
			return (0);
		}
		i++;
	}
	if (ft_atoi(str) == 0)
		return (1);
	return (check_long(str, minus));
}

static int	exit_error(char *cmd, char *err)
{
	ft_putendl_fd("exit", 2);
	ft_putstr_fd("msh: exit: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(err, 2);
	return (1);
}

int	exit_shell(char **cmd, t_data *data)
{
	int	errcode;

	if (!cmd[1])
	{
		ft_putendl_fd("exit", 1);
		exit(data->errcode);
	}
	else if (!is_num(cmd[1]))
	{
		exit_error(cmd[1], ": numeric argument required");
		data->errcode = 255;
		exit(255);
	}
	else if (cmd[2])
	{
		exit_error(NULL, "too many arguments");
		data->errcode = 1;
		return (1);
	}
	else
	{
		errcode = ft_atoi(cmd[1]);
		ft_putendl_fd("exit", 1);
		exit(errcode);
	}
}
