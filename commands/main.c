#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_list	*env_list;
	t_list	*head;
	t_list	*elem;
	
	env_list = NULL;
	(void)argc;
	(void)argv;
	
	copy_env(envp, &env_list);
	print_list(env_list);
	
	printf("----------------------------\n");

	// while (envp[i] != NULL)
    // {
    //     elem = ft_lstnew(envp[i]);
	// 	// if (!elem)
	// 	// 	ft_error(ERR_CODE_0);
	// 	ft_lstadd_back(&head, elem);
	// 	i++;
    // }
	
	export("a", "42", env_list);
	export("B", "42", env_list);
	//printf("----------------------------\n");
	print_list(env_list);
	//elem = add_prefix(env_list);
	export("a", "228", env_list);
	printf("----------------------------\n");
	print_list(elem);
	//export_sort(env_list);
	// //unset("B", &head);
	//printf("----------------------------\n");
	// print_list(elem);
	
	// while(1)
	// {
	// 	;
	// }
	
	// char *str = "abc";
	// printf("%s\n", str);
	// //str = ft_strjoin("declare -x ", str);
	// add_prefix(&str);
	// printf("%s\n", str);while(1)
	
	
}