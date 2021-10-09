/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:25:50 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 01:44:36 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "env.h"
# include "libft.h"
# include "simple_command.h"
# include "command.h"
# include "builtins.h"
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <errno.h>
# include <stdio.h>

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

typedef struct s_heredoc
{
	char	*stop_word;
	int		stop_word_len;
	int		fd;
}	t_heredoc;

t_buffer	*new_buffer(size_t len);
void		free_buffer(t_buffer *b);
t_buffer	*expand_buffer(t_buffer *b);
void		add_sym_to_buffer(t_buffer **b, char c);
void		add_str_to_buffer(t_buffer **b, char *s);

char		*doublequote_handling(char *s, t_buffer **b, t_command **cmd);
char		*doublequote_filename_handling(char *s, t_buffer **b, t_data *d);
char		*pipe_handling(t_command **cmd, t_buffer **b, char *s);
char		*quote_handling(char *s, t_buffer **b, t_command **cmd);
char		*quote_filename_handling(char *s, t_buffer **b);
char		*space_handling(char *s, t_buffer **b, t_command **cmd);
char		*backslash_handling(char *s, t_buffer **b);
char		*dollar_handling(char *s, t_buffer **b, t_data *d);
char		*heredoc_handling(char *s, t_command *cmd);
char		*redirects_handling(char *s, t_command *c);

void		free_parser(t_parser *p);
t_parser	*new_parser(t_data *d);
t_command	*parse(char *s, t_data *d);
void		clear_buffer(t_buffer *b);

char		*get_filename(char **s, t_data *d);
char		*get_heredoc_filename(int num);
void		print_err(char *file, int err);

#endif