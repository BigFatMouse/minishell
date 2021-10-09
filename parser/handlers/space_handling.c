/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:28:31 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 00:11:50 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*space_handling(char *s, t_buffer **b, t_command **cmd)
{
	if (*(*b)->content != '\0')
	{
		add_arg_to_command(cmd, ft_strdup((*b)->content));
		clear_buffer(*b);
	}
	while (*s == ' ')
		s++;
	return (s);
}
