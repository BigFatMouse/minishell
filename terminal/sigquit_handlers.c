/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 01:10:59 by klanie            #+#    #+#             */
/*   Updated: 2021/07/29 01:17:04 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

void	sigquit_msg_handler(int signum)
{
	(void) signum;
	write(1, "Quit: 3\n", 8);
}

void	sigquit_empty_handler(int signum)
{
	(void) signum;
}
