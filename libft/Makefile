# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 16:06:33 by mhogg             #+#    #+#              #
#    Updated: 2021/08/06 16:40:04 by klanie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c  ft_strrchr.c ft_strnstr.c ft_strncmp.c \
ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_strmapi.c \
ft_strright.c
BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:%.c=%.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME): $(OBJ) $(HEADER) 
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJ) $(BOBJ) $(HEADER) $(NAME)
	ar -rcs $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(SRC) $(BSRC) libft.h

.PHONY:		all bonus clean fclean re norm