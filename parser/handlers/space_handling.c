/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:28:31 by klanie            #+#    #+#             */
/*   Updated: 2021/05/17 03:07:34 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*space_handling(char *s, t_buffer **b, t_command *cmd)
{
	if (*(*b)->content != '\0')
	{
		add_arg_to_command(cmd, (*b)->content);
		free(*b);
		*b = NULL;
		*b = new_buffer(START_BUFFER_SIZE);
	}
	while (*s == ' ')
		s++;
	return (s);
}
