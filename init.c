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

void	builtin_init(t_builtin *bi)
{
	bi[0]->name = ft_strcpy(bi[0]->name, "cd");
	bi[0]->func = &builtin_cd;
	bi[1]->name = ft_strcpy(bi[1]->name, "env");
	bi[1]->func = &builtin_env;
	bi[2]->name = ft_strcpy(bi[2]->name, "setenv");
	bi[2]->func = &builtin_setenv;
	bi[3]->name = ft_strcpy(bi[3]->name, "unsetenv");
	bi[3]->func = &builtin_unsetenv;
	bi[4]->name = ft_strcpy(bi[4]->name, "exit");
	bi[4]->func = &builtin_exit;
}


t_cmd	*cmd_init(void)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	new_cmd->name = NULL;
	new_cmd->opt = NULL;
	new_cmd->arg = NULL;
	return (new_cmd);
}

t_larg	*larg_init(void)
{
	t_larg	*new_larg;

	new_larg = (t_larg *)malloc(sizeof(t_larg));
	new_larg->arg = NULL;
	new_larg->next = NULL;
	return (new_larg);
}
