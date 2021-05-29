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
	printf("----------------------------\n");
	print_list(env_list);
	
	printf("----------------------------\n");
	// printf("HOME=%s\n", get_env_value("HOME", env_list));

	// while (envp[i] != NULL)
    // {
    //     elem = ft_lstnew(envp[i]);
	// 	// if (!elem)
	// 	// 	ft_error(ERR_CODE_0);
	// 	ft_lstadd_back(&head, elem);
	// 	i++;
    // }
	
	export("a=123", env_list);
	export("B=42", env_list);
	print_list(env_list);
	printf("----------------------------\n");
	// print_list(env_list);
	// elem = add_prefix(env_list);
	// export("home", "228", env_list);
	export("HOME=42", env_list);
	print_list(env_list);
	printf("----------------------------\n");

	export_sort(env_list);
	// unset("a", &env_list);
	// printf("----------------------------\n");
	// print_list(env_list);
	
	while(1)
	{
		;
	}
	
	// char *str = "abc";
	// printf("%s\n", str);
	// //str = ft_strjoin("declare -x ", str);
	// add_prefix(&str);
	// printf("%s\n", str);while(1)
	
	
}