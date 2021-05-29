#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

#define ERR_CODE_0 "malloc error"
#define PATH_MAX 4096 

// функции для работы с перменными окружения
void	copy_env(char **envp, t_list **list);
void	print_list(t_list *list);
void	export(char *name_variable, char *value_variable, t_list *list);
void	export_sort(t_list *list);
void	unset(char *name_variable, t_list **list);

// другие build-in функции

#endif