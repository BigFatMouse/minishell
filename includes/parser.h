/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:50 by klanie            #+#    #+#             */
/*   Updated: 2021/05/30 14:34:18 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "simple_command.h"
# include "command.h"

# define START_BUFFER_SIZE 128
# define BUF_EXPAND_STEP 128

typedef struct s_buffer
{
	char		*content;
	size_t		size;
	size_t		pos;	
}	t_buffer;

typedef struct s_parser
{
	t_buffer	*buf;
	t_list		*commands;
	t_list		*current_command;
}	t_parser;

t_buffer	*new_buffer(size_t len);
void		free_buffer(t_buffer *b);
t_buffer	*expand_buffer(t_buffer *b);
void		add_sym_to_buffer(t_buffer **b, char c);
void		add_str_to_buffer(t_buffer **b, char *s);

char		*doublequote_handling(char *s, t_buffer **b);
char		*pipe_handling(t_command *cmd, t_buffer **b, char *s);
char		*quote_handling(char *s, t_buffer **b);
char		*space_handling(char *s, t_buffer **b, t_command *cmd);
char		*backslash_handling(char *s, t_buffer **b);
char		*dollar_handling(char *s, t_buffer **b, t_list *env);

void		free_parser(t_parser *p);
t_parser	*new_parser(void);
t_command	*parse(char **s, t_list *env);

#endif