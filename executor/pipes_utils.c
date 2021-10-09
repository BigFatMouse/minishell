/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:15:26 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/05 17:22:28 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	pipes_error(char *cmd, char *err, int status)
{
	ft_putstr_fd("msh: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	exit(status);
}

int	free_error(char **envp, t_data *data)
{
	free_arr(&envp);
	ft_error(data);
	return (1);
}

void	change_fd(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}
