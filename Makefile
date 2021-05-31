# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 03:10:04 by klanie            #+#    #+#              #
#    Updated: 2021/05/30 14:48:18 by klanie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SOURCES		=	$(addprefix builtins/, 										\
				cd.c														\
				env.c														\
				export.c													\
				pwd.c														\
				unset.c														\
				utils.c														\
				)															\
				$(addprefix command/, 										\
				add_arg_to_command.c										\
				add_simple_cmd_to_command.c									\
				expand_command.c											\
				free_command.c												\
				new_command.c												\
				)															\
				$(addprefix executor/, 										\
				exec_command.c												\
				)															\
				$(addprefix parser/,										\
				free_parser.c												\
				new_parser.c												\
				parse.c														\
				)															\
				$(addprefix parser/buffer/,									\
				add_str_to_buffer.c											\
				add_sym_to_buffer.c											\
				expand_buffer.c												\
				free_buffer.c												\
				new_buffer.c												\
				)															\
				$(addprefix parser/handlers/,								\
				backslash_handling.c										\
				dollar_handling.c											\
				doublequote_handling.c										\
				pipe_handling.c												\
				quote_handling.c											\
				space_handling.c											\
				)															\
				$(addprefix simple_command/,								\
				add_arg_to_simple_command.c									\
				expand_simple_command.c										\
				free_simple_command.c										\
				new_simple_command.c										\
				)															\
				main.c
HEADERS		=	includes/
OBJECTS		=	$(SOURCES:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LIBFT		=	-L libft -lft
RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJECTS)
			make bonus -C libft/
			$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

$(OBJECTS): %.o: %.c
		$(CC) $(CFLAGS) -c -I $(HEADERS) $^ -o $@

clean:
			$(RM) $(OBJECTS)
			make -C libft/ clean
			
fclean:		clean
			$(RM) $(NAME)
			make -C libft/ fclean
			
re:			fclean all

norm:
	norminette	$(SOURCES)  $(addprefix includes/,	*.h)

.PHONY:		all clean fclean re bonus norm