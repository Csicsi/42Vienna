/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krabitsc <krabitsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:31:36 by krabitsc          #+#    #+#             */
/*   Updated: 2024/11/16 16:04:05 by krabitsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char *command_name)
{
	if (!command_name)
		return (0);
	if (ft_strncmp(command_name, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(command_name, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(command_name, "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(command_name, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(command_name, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(command_name, "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(command_name, "pwd", 4) == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_cmd *cmd, t_data *data,
	t_exec_context *ctx, bool print_exit)
{
	if (cmd->empty_redir)
	{
		cleanup_data(data, false);
		free(ctx->child_pids);
		return (1);
	}
	if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (builtin_cd(cmd, data));
	else if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		return (builtin_echo(cmd));
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		return (builtin_exit(cmd, data, print_exit));
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		return (builtin_env(data));
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (builtin_export(cmd, data));
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (builtin_unset(cmd, data));
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		return (builtin_pwd(data));
	return (1);
}

int	count_cmds(t_cmd *cmd_list)
{
	int	count;

	count = 0;
	while (cmd_list)
	{
		count++;
		cmd_list = cmd_list->next;
	}
	return (count);
}
