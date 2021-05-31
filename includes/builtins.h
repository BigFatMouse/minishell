/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:33:47 by klanie            #+#    #+#             */
/*   Updated: 2021/05/31 13:20:30 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
# define ERR_CODE_0 "malloc error"
# define PATH_MAX 4096 

void	copy_env(char **envp, t_list **list);
void	env(t_list *list);
int		export(char *str, t_list *list);
void	export_sort(t_list *list);
void	unset(char *name_variable, t_list **list);
char	*get_env_value(char *name_variable, t_list *list);
int		cd(char *path, t_list *env_list);
int		pwd(void);
void	ft_error(char *str);
void	echo(char **cmd);
int		exit_shell(char **cmd);

#endif