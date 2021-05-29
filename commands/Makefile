NAME = minishell
#HEADER = minishell.h
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror 
SRC =  env.c
	
OBJ = $(SRC:%.c=%.o)

all: $(NAME)
	
# make -C libft/

$(LIBFT):
	cd libft && make 
	cd libft && make bonus

$(NAME): $(LIBFT) $(OBJ) #$(HEADER)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) -lncurses

%.o: %.c $(LIBFT) #$(HEADER) 
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re