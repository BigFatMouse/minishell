/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_simple_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:47:43 by klanie            #+#    #+#             */
/*   Updated: 2021/08/03 00:01:31 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_command.h"

t_simple_command	*new_simple_command(size_t args_num, t_data *d, void *c)
{
	t_simple_command	*scmd;
	size_t				args_size;

	scmd = NULL;
	scmd = (t_simple_command *)malloc(sizeof(t_simple_command));
	if (!scmd)
		return (NULL);
	ft_memset(scmd, 0, sizeof(t_simple_command));
	args_size = (args_num + 1) * sizeof(char *);
	scmd->available_args_num = args_num;
	scmd->fd_out = 1;
	scmd->data = d;
	scmd->parent = c;
	scmd->args = (char **)malloc(args_size);
	if (!scmd->args)
	{
		free(scmd);
		return (NULL);
	}
	ft_memset(scmd->args, 0, args_size);
	return (scmd);
}
