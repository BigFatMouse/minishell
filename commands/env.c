#include "minishell.h"

// 1 - Скопировать envp в свой список(ДЛЯ ЗАЩИТЫ)
// 2 - Написать функцию export, с добавление переменных в свой список (см. пункт 1)
// 3 - Написать unset, которая удалит переменную из списка (см. пунк 1)
// 4 - Написать просто export, тот же самый список что в 1 пункте, но отсортированный strcmp, и с прификсом declare -x.


void ft_error(char *str)
{
	ft_putendl_fd(str, 2);
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

void	export(char *name_variable, char *value_variable, t_list *list)
{
	t_list	*elem;
	t_list	*tmp;
	char	*str1;
	char	*str;
	int		i;

	str1 = ft_strjoin(name_variable, "=");
	str = ft_strjoin(str1, value_variable);
	i = 0;
	
	elem = list;
	while (elem)
	{
		if (!ft_strncmp(elem->content, str1, ft_strlen(str1))) // пробегаемся по списку, ищем есть ли уже такая переменная
		{
			tmp = elem;
			free(tmp->content);
			elem->content = ft_strdup(str); //если такая переменная уже есть, перезаписываем
			i++;
			free(str);
		}
		elem = elem->next;
	}
	if (i == 0) // если такой переменной нет, добавляем в конец списка
	{
		elem = ft_lstnew(str);
		if (!elem)
			ft_error(ERR_CODE_0);
		ft_lstadd_back(&list, elem);
	}
	free(str1);
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
		//free(str);
	}
	return (res);
}

// t_list* add_prefix(t_list* list) 
// {
// 	t_list* result;
	
// 	if (list == NULL)
// 		return NULL;
// 	result = ft_lstnew(ft_strjoin("declare -x ", list->content));
// 	result->next = ft_lstclone(list->next);
// 	return result;
// }

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
// 	t_list	*head;
// 	t_list	*elem;
// 	int		i;

// 	head = NULL;
// 	i = 0;
// 	(void)argc;
// 	(void)argv;

// 	while (envp[i] != NULL)
//     {
//         elem = ft_lstnew(envp[i]);
// 		if (!elem)
// 			ft_error(ERR_CODE_0);
// 		ft_lstadd_back(&head, elem);
// 		i++;
//     }
// 	// export("a", "42", head);
// 	// export("B", "42", head);
// 	printf("----------------------------\n");
// 	print_list(head);
// 	//elem = add_prefix(head);
// 	// export("a", "228", head);
// 	// printf("----------------------------\n");
// 	// print_list(elem);
// 	elem = export_sort(head);
// 	// //unset("B", &head);
// 	printf("----------------------------\n");
// 	print_list(elem);
	
// 	while(1)
// 	{
// 		;
// 	}
	
// 	// char *str = "abc";
// 	// printf("%s\n", str);
// 	// //str = ft_strjoin("declare -x ", str);
// 	// add_prefix(&str);
// 	// printf("%s\n", str);while(1)
	
	
// }