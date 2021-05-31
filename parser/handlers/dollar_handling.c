/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:51:02 by klanie            #+#    #+#             */
/*   Updated: 2021/05/29 20:20:05 by klanie           ###   ########.fr       */
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
	free(buf);
	if (*env_key)
		return (1);
	return (0);
}

static char	*get_env_value(char *needle_env_key, t_list *env)
{
	char	**token;

	while (env)
	{
		token = ft_split(env->content, '=');
		if (!ft_strncmp(needle_env_key, token[0], ft_strlen(token[0]) + 1))
		{
			free(token[0]);
			free(token);
			return (token[1]);
		}
		else
		{
			free(token[0]);
			free(token[1]);
			free(token);
			env = env->next;
		}
	}
	return (NULL);
}

char	*dollar_handling(char *s, t_buffer **b, t_list *env)
{
	char	*env_key;
	char	*env_value;

	if (ft_isdigit(*(s + 1)) || !is_key(*(s + 1)))
	{
		add_sym_to_buffer(b, *s);
		return (s + 1);
	}
	env_key = NULL;
	if (!get_env_key(&env_key, &s))
		return (s + 1);
	env_value = get_env_value(env_key, env);
	if (!env_value)
		return (s);
	add_str_to_buffer(b, env_value);
	return (s);
}
