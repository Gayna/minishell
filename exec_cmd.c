/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 04:34:30 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/28 04:34:30 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

static int	get_next_path(char *path, char *path_line)
{
	static int	offset = 0;
	int		it;

	offset = (path_line[offset] == ':')? offset + 1 : offset;
	it = offset;
	while (path_line[offset] != ':' && path_line[offset] != '\0')
	{
		path[offset - it] = path_line[offset];
		offset++;
	}
	path[it - offset] = '\0';
	return (offset - it);
}
static int	exec_fork(t_cmd *cmd, char **envp)
{
	int	it;
	char	path[MAX_PATH_SIZE];

	if (envp != NULL)
	{
		while (ft_strncmp("PATH=", envp[it], 5))
			++it;
	}
	while (get_next_path(path, envp[it]))
		execve(ft_strjoin(path, cmd->name), arg_to_array(cmd), envp);
	ft_putstr("ft_sh1: command not found: ");
	ft_putstr(cmd->name);
	ft_putchar('\n');
	return (ERR);
}

static int	exec_bin(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int	res;

	res = ERR;
	if ((pid = fork()) != 0)
		waitpid(pid, &res, 0);
	else
		exec_fork(cmd, envp);
	return (res);
}

int		exec_cmd(t_cmd		*cmd,
					 t_builtin	*bi,
					 char		**envp)
{
	int	it;

	it = -1;
	if (cmd == NULL)
		return (NULL_CMD);
	while (++it < NBR_FUNC)
	{
		if (ft_strcmp(cmd->name, bi[it]->name))
			return (bi[it]->func(cmd, envp));
	}
	return (exec_bin(cmd, envp));
}
