#include "builtins.h"

static int	ft_isnum(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int			exit_shell(char **cmd)
{
	int	errcode;

	if (!cmd[0])
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	if (!ft_isnum(cmd[0]))
	{
		ft_putendl_fd("minishell: exit: numeric argument required", 2);
		errcode = 255;
		return (1);
	}
	else if (cmd[1])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		errcode = 1;
		return (1);
	}
	else
	{
		errcode = atoi(cmd[0]);
		ft_putendl_fd("exit", 1);
		exit(errcode);
	}
}
