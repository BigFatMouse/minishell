/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klanie <klanie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:47:18 by klanie            #+#    #+#             */
/*   Updated: 2021/08/06 00:10:29 by klanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "simple_command.h"
# include <unistd.h>

# define START_CMD_NUM		5
# define CMD_EXPAND_STEP	5

// Command base structure type
// 
// available_commands_num: The number of SimpleCommands for which memory is
// allocated
// commands_num: Current number of arguments
// commands: Array of SimpleCommands
// heredocs: List of names of temporary heredoc files
// heredocs_num: Number of temporary heredoc files
typedef struct s_command
{
	int					available_commands_num;
	int					commands_num;
	t_simple_command	**commands;
	t_list				*heredocs;
	int					heredocs_num;
	int					is_sigint;
	t_data				*data;
}	t_command;

// Create new [t_command] and returns pointer
// cmd_num: Number of stored SimpleCommands
t_command				*new_command(size_t cmd_num, t_data *d);

// Increase the number of stored SimpleCommands (cmd.commands realloc)
// Returns a pointer to the new expanded element, the old one is freed
t_command				*expand_command(t_command *cmd);

// Free the memory occupied by the element (including content)
void					free_command(void *cmd);

// Adds a command. Expands the allocated memory as needed
void					add_simple_cmd_to_command(t_command **cmd, \
												t_simple_command *scmd);

// Adds an argument to last SimpleCommand in Command
void					add_arg_to_command(t_command **cmd, char *arg);

#endif
