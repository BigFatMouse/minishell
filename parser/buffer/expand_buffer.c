/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:18:36 by klanie            #+#    #+#             */
/*   Updated: 2021/05/16 22:24:15 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_buffer	*expand_buffer(t_buffer *b)
{
	t_buffer	*new_b;

	new_b = new_buffer(b->size + 128);
	if (!new_b)
		return (NULL);
	ft_strlcpy(new_b->content, b->content, b->size + 1);
	new_b->size = b->size + 128;
	new_b->pos = b->pos;
	free_buffer(b);
	return (new_b);
}
