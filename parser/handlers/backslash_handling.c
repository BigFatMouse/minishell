/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:02:58 by klanie            #+#    #+#             */
/*   Updated: 2021/07/26 22:04:20 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "parser.h"

char	*backslash_handling(char *s, t_buffer **b)
{
	add_sym_to_buffer(b, *(s + 1));
	return (s + 1);
}
