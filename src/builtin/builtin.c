/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:02:47 by joao-alm          #+#    #+#             */
/*   Updated: 2025/04/04 15:02:50 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "jal_string.h"

int	ft_is_builtin(const char *cmd)
{
	if (!cmd)
		return (1);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"pwd") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit"));
}

void	ft_exec_builtin(t_command *command, char ***envp)
{
	if (!ft_strcmp(command->cmd, "echo"))
		ft_echo(command);
	if (!ft_strcmp(command->cmd, "cd"))
		ft_cd(command, envp);
	if (!ft_strcmp(command->cmd, "pwd"))
		ft_pwd(command, (const char **)*envp);
	if (!ft_strcmp(command->cmd, "export"))
		ft_export(command, envp);
	if (!ft_strcmp(command->cmd, "unset"))
		ft_unset(command, envp);
	if (!ft_strcmp(command->cmd, "env"))
		ft_env(command, (const char **)*envp);
	if (!ft_strcmp(command->cmd, "exit"))
		ft_exit(command, *envp);
}
