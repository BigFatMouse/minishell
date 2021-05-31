#include "builtins.h"

int	pwd(void)
{
	char	path[PATH_MAX];

	getcwd(path, PATH_MAX);
	ft_putendl_fd(path, 1);
	return (0);
}
