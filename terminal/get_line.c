/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:25:56 by klanie            #+#    #+#             */
/*   Updated: 2021/07/26 01:17:10 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

char	*get_line(const char *prompt)
{
	char	*line;

	line = NULL;
	line = readline(prompt);
	if (line && *line)
		add_history(line);
	return (line);
}
