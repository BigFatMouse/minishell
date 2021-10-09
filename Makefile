# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 03:10:04 by klanie            #+#    #+#              #
#    Updated: 2021/08/06 16:39:55 by klanie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
SOURCES		=	$(addprefix builtins/, 										\
					cd.c													\
					echo.c													\
					env.c													\
					exit.c													\
					export.c												\
					pwd.c													\
					unset.c													\
					utils.c													\
				)															\
				$(addprefix command/, 										\
					add_arg_to_command.c									\
					add_simple_cmd_to_command.c								\
					expand_command.c										\
					free_command.c											\
					new_command.c											\
				)															\
				$(addprefix executor/, 										\
					exec_command.c											\
					exec_utils.c											\
					pipes_utils.c											\
					pipes.c													\
				)															\
				$(addprefix parser/,										\
					free_parser.c											\
					new_parser.c											\
					parse.c													\
					utils.c													\
				)															\
				$(addprefix parser/buffer/,									\
					add_str_to_buffer.c										\
					add_sym_to_buffer.c										\
					clear_buffer.c											\
					expand_buffer.c											\
					free_buffer.c											\
					new_buffer.c											\
				)															\
				$(addprefix parser/handlers/,								\
					backslash_handling.c									\
					dollar_handling.c										\
					doublequote_handling.c									\
					heredoc_handling.c										\
					pipe_handling.c											\
					quote_handling.c										\
					redirects_handling.c									\
					space_handling.c										\
				)															\
				$(addprefix simple_command/,								\
					add_arg_to_simple_command.c								\
					expand_simple_command.c									\
					free_simple_command.c									\
					new_simple_command.c									\
				)															\
				$(addprefix terminal/,										\
					get_line.c												\
					increment_shlvl.c										\
					setup_terminal.c										\
					sigint_handlers.c										\
					sigquit_handlers.c										\
				)															\
				main.c
HEADERS		=	includes/
OBJECTS		=	$(SOURCES:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIBFT		=	-L libft -lft
RDLINE_LIB	=	-L/Users/$(USER)/.brew/Cellar/readline/8.1/lib -lreadline
RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJECTS) $(addprefix includes/, *.h)
			make bonus -C libft/
			$(CC) $(CFLAGS) $(LIBFT) $(RDLINE_LIB) $(OBJECTS) -o $(NAME)

$(OBJECTS): %.o: %.c $(addprefix includes/, *.h)
		$(CC) $(CFLAGS) -c -I $(HEADERS) $< -o $@ 

clean:
			$(RM) $(OBJECTS)
			make -C libft/ clean
			
fclean:		clean
			$(RM) $(NAME)
			make -C libft/ fclean
			
re:			fclean all

norm:
			@norminette $(SOURCES) $(addprefix includes/, *.h)
			@make -C libft/ norm

sign:
			/usr/libexec/PlistBuddy -c "Add :com.apple.security.get-task-allow bool true" tmp.entitlements
			codesign -s - --entitlements tmp.entitlements -f $(NAME)
			rm tmp.entitlements

.PHONY:		all clean fclean re norm sign