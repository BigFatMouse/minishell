#include "builtins.h"

static char	*get_env_name(char *str)
{
	int		len;
	char	*res;

	len = 0;
	while (str[len] != '=')
	{
		if (str[len] == '\0')
			return (str);
		len++;
	}
	res = ft_substr(str, 0, len);
	return (res);
}

static void	print_export_list(t_list *list)
{
	char	*str;
	int		i;

	while (list)
	{
		ft_putstr_fd("declare -x ", 1);
		str = ft_strdup(list->content);
		i = 0;
		while (str[i] != '=')
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "=", 1);
		ft_putchar_fd(34, 1);
		while (str[i++] != '\0')
		{
			i++;
			write(1, &str[i], 1);
		}
		free(str);
		ft_putchar_fd(34, 1);
		write(1, "\n", 1);
		list = list->next;
	}
}

int	export(char *str, t_list *list)
{
	t_list	*elem;
	char	*str1;
	char	*name_variable;

	name_variable = get_env_name(str);
	str1 = ft_strjoin(name_variable, "=");
	free(name_variable);
	elem = list;
	while (elem)
	{
		if (!ft_strncmp(elem->content, str1, ft_strlen(str1)))
		{
			elem->content = ft_strdup(str);
			free(str1);
			return (0);
		}
		elem = elem->next;
	}
	elem = ft_lstnew(str);
	if (!elem)
		ft_error(ERR_CODE_0);
	ft_lstadd_back(&list, elem);
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
	print_export_list(list);
}
