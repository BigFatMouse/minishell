/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:18:02 by klanie            #+#    #+#             */
/*   Updated: 2021/05/17 03:07:06 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_buffer	*new_buffer(size_t len)
{
	t_buffer	*b;

	b = NULL;
	b = (t_buffer *)malloc(sizeof(t_buffer));
	if (!b)
		return (NULL);
	ft_memset(b, 0, sizeof(t_buffer));
	b->content = (char *)malloc((len + 1) * sizeof(char));
	if (!b->content)
	{
		free(b);
		return (NULL);
	}
	ft_bzero(b->content, len + 1);
	b->size = len;
	return (b);
}
