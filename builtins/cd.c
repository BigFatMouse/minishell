#include "builtins.h"

// обработать случай, когда путь начинается с #

static int	cd_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}

int	cd(char *path, t_list *env_list)
{
	char	old_path[PATH_MAX];
	char	new_path[PATH_MAX];
	char	*new_pwd;
	char	*old_pwd;
	int		is_arg;

	is_arg = 1;
	getcwd(old_path, PATH_MAX);
	if (path == NULL)
	{
		path = get_env_value("HOME", env_list);
		is_arg = 0;
	}
	if (chdir(path))
		cd_error(path);
	getcwd(new_path, PATH_MAX);
	old_pwd = ft_strjoin("OLDPWD=", old_path);
	new_pwd = ft_strjoin("PWD=", new_path);
	export(old_pwd, env_list);
	export(new_pwd, env_list);
	free(old_pwd);
	free(new_pwd);
	if (!is_arg)
		free(path);
	return (0);
}
