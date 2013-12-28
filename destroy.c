/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 04:00:00 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/28 04:00:00 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

void	destroy_cmd(t_cmd **cmd)
{
	free(cmd->name);
	destroy_lopt(cmd->opt);
	destroy_larg(cmd->arg);
	free(cmd);
	return ;
}


void	destroy_lopt(t_lopt *opt)
{
	if (opt == NULL)
		return ;
	free(opt->name);
	destroy_lopt(opt->next);
	free(opt);
	return ;
}


void	destroy_larg(t_larg *arg)
{
	if (arg == NULL)
		return ;
	free(arg->name);
	destroy_larg(arg->next);
	free(arg);
	return ;
}
