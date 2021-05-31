#include "builtins.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
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
