#include "builtins.h"

void	env(t_list *list)
{
	t_list	*tmp;

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
