#include "builtins.h"

void	echo(char **cmd)
{
	if (!ft_strncmp("-n", cmd[0], strlen(cmd[0]) + 1))
	{
		if (cmd[1])
			ft_putstr_fd(cmd[1], 1);
	}
	else
	{
		if (cmd[0])
			ft_putendl_fd(cmd[0], 1);
		else
			write(1, "\n", 1);
	}
}
