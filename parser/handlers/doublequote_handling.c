/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublequote_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:29:32 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 00:27:30 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_shielded(char c)
{
	if (ft_strchr("$\"\\", c))
		return (1);
	return (0);
}

char	*doublequote_filename_handling(char *s, t_buffer **b, t_data *d)
{
	s++;
	while (*s && *s != '\"')
	{
		if (*s == '\\' && is_shielded(*(s + 1)))
			s = backslash_handling(s, b);
		else if (*s == '$')
		{
			s = dollar_handling(s, b, d);
			s--;
		}
		else
			add_sym_to_buffer(b, *s);
		if (*s == '\"')
			break ;
		s++;
	}
	if (*s == '\"' && *(s - 1) != '\"' && *(s - 1) != '\'')
		s++;
	return (s);
}

static int	check_quotes(char *s, t_command **cmd, t_buffer **b)
{
	if (*(s + 1) == '\"' && *(s + 2) != '\"' && *(s + 2) != '\'')
	{
		add_sym_to_buffer(b, '\0');
		add_arg_to_command(cmd, ft_strdup((*b)->content));
		clear_buffer(*b);
		return (0);
	}
	return (1);
}

char	*doublequote_handling(char *s, t_buffer **b, t_command **cmd)
{
	if (!check_quotes(s, cmd, b))
		return (s + 2);
	s++;
	while (*s && *s != '\"')
	{		
		if (*s == '\\' && is_shielded(*(s + 1)))
			s = backslash_handling(s, b);
		else if (*s == '$')
		{
			s = dollar_handling(s, b, (*cmd)->data);
			s--;
		}
		else
			add_sym_to_buffer(b, *s);
		if (*s == '\"')
			break ;
		s++;
	}
	if (*s == '\"' && *(s - 1) != '\"' && *(s - 1) != '\'')
		s++;
	return (s);
}
