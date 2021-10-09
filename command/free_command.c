/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:02:09 by klanie            #+#    #+#             */
/*   Updated: 2021/07/16 02:28:19 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

static void	free_simple_commands(t_simple_command **cmds, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (cmds[i])
			free_simple_command(cmds[i]);
		i++;
	}
	free(cmds);
}

static void	free_heredoc(void *h)
{
	char	*s;

	s = (char *)h;
	unlink(s);
	free(s);
}

void	free_command(void *cmd)
{
	t_command	*c;

	c = (t_command *)cmd;
	if (!cmd)
		return ;
	if (c->commands && c->commands_num > 0)
		free_simple_commands(c->commands, c->commands_num);
	ft_lstclear(&c->heredocs, &free_heredoc);
	free(cmd);
}
