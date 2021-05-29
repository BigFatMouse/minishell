#include "minishell.h"

// copy_env - копирует envp в свой env-список(ДЛЯ ЗАЩИТЫ)
// print_list - печатет env-список
// export - добавляет переменную в env-список, если ее там нет или заменяет существующую
// unset - удаляет переменную из env-списка
// export_sort - выводит отсортированный env-список с прификсом declare -x
// get_env_value - принмает имя переменной из env-списка, возвращает значение этой перменной 
// get_env_name - берет из строки env имя переменной до =

// - добавить кавычки в export_sort

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
}

char	*get_env_name(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;

	while (str[len] != '=')
	{
		if (str[len] == '\0')
			return (str);
		len++;
	}
	res = ft_substr(str, 0, len + 1);
	return (res);
}

void	print_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
}

void	copy_env(char **envp, t_list **head)
{
	t_list	*elem;
	int		i;
	
	i = 0;
	while (envp[i] != NULL)
	{
		elem = ft_lstnew(envp[i]);
		if (!elem)
			ft_error(ERR_CODE_0);
		ft_lstadd_back(head, elem);
		i++;
	}
}

// void	export(char *name_variable, char *value_variable, t_list *list)
// {
// 	t_list	*elem;
// 	t_list	*tmp;
// 	char	*str1;
// 	char	*str;
// 	int		i;

// 	str1 = ft_strjoin(name_variable, "=");
// 	str = ft_strjoin(str1, value_variable);
// 	i = 0;
	
// 	elem = list;
// 	while (elem)
// 	{
// 		if (!ft_strncmp(elem->content, str1, ft_strlen(str1))) // пробегаемся по списку, ищем есть ли уже такая переменная
// 		{
// 			tmp = elem;
// 			free(tmp->content);
// 			elem->content = ft_strdup(str); //если такая переменная уже есть, перезаписываем
// 			i++;
// 			free(str);
// 		}
// 		elem = elem->next;
// 	}
// 	if (i == 0) // если такой переменной нет, добавляем в конец списка
// 	{
// 		elem = ft_lstnew(str);
// 		if (!elem)
// 			ft_error(ERR_CODE_0);
// 		ft_lstadd_back(&list, elem);
// 	}
// 	free(str1);
// }

int	export(char *str, t_list *list)
{
	t_list	*elem;
	t_list	*tmp;
	char	*str1;

	str1 = get_env_name(str);
	
	elem = list;
	while (elem)
	{
		if (!ft_strncmp(elem->content, str1, ft_strlen(str1))) // пробегаемся по списку, ищем есть ли уже такая переменная
		{
			elem->content = ft_strdup(str); //если такая переменная уже есть, перезаписываем
			free(str1);
			return (0);
		}
		elem = elem->next;
	}
	// если такой переменной нет, добавляем в конец списка
	elem = ft_lstnew(str);
	if (!elem)
		ft_error(ERR_CODE_0);
	ft_lstadd_back(&list, elem);
	free(str1);
	return (0);
}

t_list	*add_prefix(t_list *list)
{
	t_list	*res;
	t_list	*new;
	char	*str;
	
	if (!list)
		return (NULL);
	res = NULL;
	while (list)
	{
		new = ft_lstnew(ft_strjoin("declare -x ", list->content));
		if (!new)
		{
			ft_lstclear(&res, free);
			return (NULL);
		}
		list = list->next;
		ft_lstadd_back(&res, new);
	}
	return (res);
}

char	*get_env_value(char *name_variable, t_list *list)
{
	char	*str1;

	str1 = ft_strjoin(name_variable, "=");
	while (list)
	{
		if (!ft_strncmp(list->content, str1, ft_strlen(str1)))
			return (ft_strdup(list->content + ft_strlen(str1)));
		list = list->next;
	}
	free(str1);
	return (0);
}

void	export_sort(t_list *list)
{
	t_list	*elem;
	int		size;
	int		i;
	int		j;
	char	*tmp;
	
	i = 0;
	j = 0;
	
	size = ft_lstsize(list);
	while (i < size - 1)
	{
		j = 0;
		elem = list;
		while (j < size - 1)
		{	
			elem->next = elem->next;
			if (ft_strncmp(elem->content, elem->next->content, ft_strlen(elem->content)) > 0)
			{
				tmp = elem->content;
				elem->content = elem->next->content;
				elem->next->content = tmp;
			}
			j++;
			elem = elem->next;
		}
		i++;
	}
	print_list(add_prefix(list));
}

void	unset(char *name_variable, t_list **list)
{
	t_list	*head;
	t_list	*tmp;
	char	*str1;

	head = *list;
	str1 = ft_strjoin(name_variable, "=");
	
	if (!ft_strncmp(head->content, str1, ft_strlen(str1))) //отдельно удаление первого элемента листа
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	else
	{
		while (head->next)
		{
			if (!ft_strncmp(head->next->content, str1, ft_strlen(str1)))  // если находим совпадение в следующем элементе списка
			{
				tmp = head->next;
				head->next = head->next->next;
				ft_lstdelone(tmp, free);
			}
			if (head->next != NULL)
				head = head->next;
		}
	}
	free(str1);
}

// int		main(int argc, char **argv, char **envp)
// {

// 	char *str = "abcd=456";
// 	printf("%s\n", get_env_name(str));
// 	t_list	*head;
// 	t_list	*elem;
// 	int		i;

// 	head = NULL;
// 	i = 0;
// 	(void)argc;
// 	(void)argv;
// 	copy_env(envp, &head);
// 	print_list(head);

// 	printf("----------------------------\n");

	// while (envp[i] != NULL)
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }

	// printf("----------------------------\n");
	// while (envp[i] != NULL)
    // {
    //     elem = ft_lstnew(envp[i]);
	// 	// if (!elem)
	// 	// 	ft_error(ERR_CODE_0);
	// 	ft_lstadd_back(&head, elem);
	// 	i++;
    // }
	// export("a", "42", head);
	// export("B", "42", head);
	// print_list(head);
	// printf("----------------------------\n");
// 	//elem = add_prefix(head);
// 	// export("a", "228", head);
// 	// printf("----------------------------\n");
// 	// print_list(elem);
// 	elem = export_sort(head);
// 	// //unset("B", &head);
// 	printf("----------------------------\n");
// 	print_list(elem);
	
	// while(1)
	// {
	// 	;
	// }
	
// 	// char *str = "abc";
// 	// printf("%s\n", str);
// 	// //str = ft_strjoin("declare -x ", str);
// 	// add_prefix(&str);
// 	// printf("%s\n", str);while(1)
// }