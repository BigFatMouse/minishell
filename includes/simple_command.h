/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:20:20 by klanie            #+#    #+#             */
/*   Updated: 2021/08/02 23:57:29 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_COMMAND_H
# define SIMPLE_COMMAND_H
# include <stdlib.h>
# include "libft.h"
# include "env.h"

# define START_AVAILABLE_ARGS	5
# define ARGS_EXPAND_STEP		5

// SimpleCommand base structure type
// 
// available_args_num: The number of arguments for which memory is allocated
// args_num: Current number of arguments
// args: Array of arguments
// fd_in: The file descriptor of the input redirect
// fd_out: The file descriptor of the output redirect 
typedef struct s_simple_command
{
	int				available_args_num;
	int				args_num;
	char			**args;
	int				fd_in;
	int				fd_out;
	int				err;
	t_data			*data;
	void			*parent;
}	t_simple_command;

// Create new [t_simple_command] and returns pointer
// args_num: Number of stored arguments
t_simple_command	*new_simple_command(size_t args_num, t_data *d, \
										void *c);

// Increase the number of stored arguments (cmd.args realloc)
// Returns a pointer to the new expanded element, the old one is freed
t_simple_command	*expand_simple_command(t_simple_command *cmd);

// Free the memory occupied by the element (including content)
void				free_simple_command(void *cmd);

// Adds an argument. Expands the allocated memory as needed
void				add_arg_to_simple_command(t_simple_command **cmd, \
											char *arg);

#endif
