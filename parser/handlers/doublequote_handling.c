/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublequote_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:29:32 by klanie            #+#    #+#             */
/*   Updated: 2021/05/29 17:55:27 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_shielded(char c)
{
	if (ft_strchr("$\"\\", c))
		return (1);
	return (0);
}

char	*doublequote_handling(char *s, t_buffer **b)
{
	s++;
	while (*s != '\"')
	{
		if (*s == '\\' && is_shielded(*(s + 1)))
			s = backslash_handling(s, b);
		else
			add_sym_to_buffer(b, *s);
		s++;
	}
	return (++s);
}
