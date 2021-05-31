#include "builtins.h"

void	unset(char *name_variable, t_list **list)
{
	t_list	*head;
	t_list	*tmp;
	char	*str1;

	head = *list;
	str1 = ft_strjoin(name_variable, "=");
	if (!ft_strncmp(head->content, str1, ft_strlen(str1)))
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	else
	{
		while (head->next)
		{
			if (!ft_strncmp(head->next->content, str1, ft_strlen(str1)))
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
