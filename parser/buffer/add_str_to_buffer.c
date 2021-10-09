/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:21:57 by klanie            #+#    #+#             */
/*   Updated: 2021/05/29 18:24:30 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_str_to_buffer(t_buffer **b, char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		add_sym_to_buffer(b, *s);
		s++;
	}
}
