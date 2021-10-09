/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:51:02 by klanie            #+#    #+#             */
/*   Updated: 2021/08/05 01:43:50 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_key(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

static int	get_env_key(char **env_key, char **s)
{
	t_buffer	*buf;

	buf = new_buffer(START_BUFFER_SIZE);
	*s = (*s + 1);
	while (is_key(**s))
	{
		add_sym_to_buffer(&buf, **s);
		*s = (*s + 1);
	}
	*env_key = buf->content;
	if (*env_key)
	{
		free(buf);
		return (1);
	}
	free_buffer(buf);
	return (0);
}

static void	write_last_status(t_buffer **b, t_data *d)
{
	char	*code;

	code = ft_itoa(d->errcode);
	add_str_to_buffer(b, code);
	free(code);
}

char	*dollar_handling(char *s, t_buffer **b, t_data *d)
{
	char	*env_key;
	char	*env_value;

	if (*(s + 1) == '?')
	{
		write_last_status(b, d);
		return (s + 2);
	}
	if (ft_isdigit(*(s + 1)) || !is_key(*(s + 1)))
	{
		add_sym_to_buffer(b, *s);
		return (s + 1);
	}
	env_key = NULL;
	if (!get_env_key(&env_key, &s))
		return (s + 1);
	env_value = get_env_value(env_key, d->env_list);
	if (env_value)
		add_str_to_buffer(b, env_value);
	free(env_key);
	free(env_value);
	return (s);
}
