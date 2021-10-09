/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:54:08 by mhogg             #+#    #+#             */
/*   Updated: 2021/08/05 15:15:30 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "libft.h"

typedef struct s_data
{
	t_list		*env_list;
	int			errcode;
	int			fd[2];
	pid_t		*pid;
}	t_data;

#endif