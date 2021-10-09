/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sym_to_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:18:53 by klanie            #+#    #+#             */
/*   Updated: 2021/05/29 17:54:41 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_sym_to_buffer(t_buffer **b, char c)
{
	if ((*b)->pos + 1 > (*b)->size)
		*b = expand_buffer(*b);
	(*b)->content[(*b)->pos] = c;
	(*b)->pos++;
}
