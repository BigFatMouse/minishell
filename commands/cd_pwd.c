#include "minishell.h"

// pwd - выводит текущий путь
// cd - меняет текущий каталог, принимает относительный и абсолютный путь, записывает в env-список старый путь
// cd без аргументов - меняет текущий каталог на путь из из env HOME
// - добавить в env pwd новый путь (абсолютный)??
// - обработать ошибки: когда путь не открылся, когда пути не существует (через errno?)

int pwd(void)
{
	char	path[PATH_MAX];

	getcwd(path, PATH_MAX);
	ft_putendl_fd(path, 1);
	return(0);
}

int cd(char *path, t_list *env_list)
{
	char	old_path[PATH_MAX];
	int		error;

	if (path == NULL)
	{
		error = chdir(get_env_value("HOME", env_list));
		strerror(error);
		return (0);
	}
	error = chdir(path);
	strerror(error);
	printf ("%s\n", strerror(error));
	getcwd(old_path, PATH_MAX);
	printf("old_path = %s\n", old_path);
	printf("new_path = %s\n", path);
	//export("OLDPWD", old_path, env_list);
	return(0);
}

int main(int argc, char **argv, char **envp)
{   
	int		error;
	
	char path[PATH_MAX];
	errno = 0;
	
	printf("%s\n", getcwd(path, PATH_MAX));
	error = chdir("..");
	if (error != 0)
	{
		strerror(error);
		printf ("%s\n", strerror(errno));
	}
	printf("%s\n", getcwd(path, PATH_MAX));
	// pwd();
	// cd("abc", env_list);
	// print_list(env_list);
	return 0;
}