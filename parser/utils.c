/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 01:24:38 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 02:28:06 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_filename(char **s, t_data *d)
{
	t_buffer	*b;
	char		*file;

	b = NULL;
	b = new_buffer(START_BUFFER_SIZE);
	if (!b)
		return (NULL);
	while (**s && **s != ' ' && **s != '|' && **s != '>' && **s != '<')
	{
		if (**s == '\"')
			*s = doublequote_filename_handling(*s, &b, d);
		else if (**s == '\'')
			*s = quote_filename_handling(*s, &b);
		else if (**s == '$')
			*s = dollar_handling(*s, &b, d);
		else
		{
			add_sym_to_buffer(&b, **s);
			(*s)++;
		}
	}
	file = ft_strdup(b->content);
	free_buffer(b);
	return (file);
}

char	*get_heredoc_filename(int num)
{
	char	*num_str;
	char	*file;

	num_str = NULL;
	num_str = ft_itoa(num);
	if (!num_str)
		return (NULL);
	file = ft_strjoin(".heredoc_", num_str);
	free(num_str);
	return (file);
}

void	print_err(char *file, int err)
{
	ft_putstr_fd("msh: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(err), 2);
}
