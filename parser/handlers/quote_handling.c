/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:29:11 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 00:30:43 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*quote_filename_handling(char *s, t_buffer **b)
{
	s++;
	while (*s != '\'')
	{
		add_sym_to_buffer(b, *s);
		s++;
	}
	return (++s);
}

char	*quote_handling(char *s, t_buffer **b, t_command **cmd)
{
	if (*(s + 1) == '\'' && *(s + 2) != '\"' && *(s + 2) != '\'')
	{
		add_sym_to_buffer(b, '\0');
		add_arg_to_command(cmd, ft_strdup((*b)->content));
		clear_buffer(*b);
		return (s + 2);
	}
	s++;
	while (*s != '\'')
	{
		add_sym_to_buffer(b, *s);
		s++;
	}
	return (++s);
}
