/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:12:45 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/02 20:12:46 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	pwd(int fd, t_data *data)
{
	char	path[PATH_MAX];

	if (!getcwd(path, PATH_MAX))
		ft_error(data);
	ft_putendl_fd(path, fd);
	data->errcode = 0;
	return (0);
}
