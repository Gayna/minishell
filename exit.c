/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 03:38:32 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/29 03:38:32 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

int	builtin_exit(t_cmd *cmd, char **envp)
{
	int	res;

	res = (cmd->arg != NULL)? ft_atoi(cmd->arg->arg) : cmd->last_return_val;
	exit(res);
}
