/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_simple_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:47:43 by klanie            #+#    #+#             */
/*   Updated: 2021/05/06 02:44:29 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_command.h"
#include <string.h>

t_simple_command	*new_simple_command(size_t args_num)
{
	t_simple_command	*scmd;
	size_t				args_size;

	scmd = NULL;
	scmd = (t_simple_command *)malloc(sizeof(t_simple_command));
	if (!scmd)
		return (NULL);
	args_size = (args_num + 1) * sizeof(char *);
	scmd->args_num = 0;
	scmd->available_args_num = args_num;
	scmd->args = (char **)malloc(args_size);
	if (!scmd->args)
	{
		free(scmd);
		return (NULL);
	}
	memset(scmd->args, 0, args_size);
	return (scmd);
}
