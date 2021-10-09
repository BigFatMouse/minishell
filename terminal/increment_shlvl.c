/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_shlvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 23:04:46 by klanie            #+#    #+#             */
/*   Updated: 2021/08/05 20:10:25 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "builtins.h"

static int	get_shlvl(t_list *env)
{
	char	*val;
	int		mshlvl;

	mshlvl = 0;
	val = get_env_value("SHLVL", env);
	if (val)
	{
		mshlvl = ft_atoi(val);
		free(val);
	}
	return (mshlvl);
}

int	increment_shlvl(t_data *data)
{
	int		shlvl;
	char	*strnum;
	char	*entry;

	shlvl = get_shlvl(data->env_list);
	shlvl++;
	strnum = ft_itoa(shlvl);
	if (shlvl == 1000)
		entry = ft_strdup("SHLVL=");
	if (shlvl < 0)
		entry = ft_strdup("SHLVL=0");
	else
		entry = ft_strjoin("SHLVL=", strnum);
	export_env(entry, data);
	free(strnum);
	free(entry);
	return (shlvl);
}
