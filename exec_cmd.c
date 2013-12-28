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
#include "exec_cmd.h"

int	exec_cmd(t_cmd		*cmd,
				 t_builtin	*bi,
				 char		**envp)
{
	int	it;

	it = -1;
	while (++it < NBR_FUNC)
	{
		if (ft_strcmp(cmd->name, bi[it]->name))
			return (bi[it]->func(cmd, envp));
	}

}
