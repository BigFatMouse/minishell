/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:32:10 by klanie            #+#    #+#             */
/*   Updated: 2021/05/17 03:05:32 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_parser(t_parser *p)
{
	if (!p)
		return ;
	if (p->buf)
		free_buffer(p->buf);
	if (p->commands)
		ft_lstclear(&p->commands, &free_command);
}
