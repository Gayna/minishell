/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 07:30:12 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/27 07:30:12 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

t_cmd	*cmd_init(void)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd)malloc(sizeof(t_cmd));
	new_cmd->cmd_name = NULL;
	new_cmd->cmd_opt = NULL;
	new_cmd->cmd_arg = NULL;
	return (new_cmd);
}


t_lopt	*lopt_init(void)
{
	t_lopt	*new_lopt;

	new_lopt = (t_lopt)malloc(sizeof(t_lopt));
	new_lopt->opt = NULL;
	new_lopt->next = NULL;
	return (new_lopt);
}


t_larg	*larg_init(void)
{
	t_larg	*new_larg;

	new_larg = (t_larg)malloc(sizeof(t_larg));
	new_larg->arg = NULL;
	new_larg->next = NULL;
	return (new_larg);
}
