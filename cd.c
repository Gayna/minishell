/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 10:13:21 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/29 10:13:21 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

static char	*extract_home(char **envp)
{
	int	it;

	it = 0;
	while (ft_strncmp(envp[it], "HOME=", 5))
		it++;
	return (envp[it] + 5);
}

static int		old_path(char **envp)
{
	int	it;

	it = 0;
	while (ft_strncmp(envp[it], "OLDPWD=", 7))
		it++;
	return (chdir(envp[it] + 7));
}


int			builtin_cd(t_cmd *cmd, char **envp)
{
	if (cmd == NULL)
		return (ERR);
	if (ft_strncmp(cmd->arg, "-") && cmd->arg->next == NULL)
		return (old_path(envp));
	if (cmd->arg == NULL)
		return (chdir(extract_home(envp)));
	return (chdir(cmd->arg));
}
