/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 09:38:32 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/27 09:38:32 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

t_lopt	*add_opt(t_cmd *cmd, char *opt)
{
	t_lopt	*new_opt;
	t_lopt	*tmp;

	if (cmd == NULL)
		return (NULL);
	if (opt == NULL)
		return (cmd->opt);
	new_opt = lopt_init();
	new_opt->opt = ft_strdup(opt);
	tmp = cmd->opt;
	if (tmp == NULL)
		return (new_opt);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_opt;
	return (cmd->opt);
}


t_larg	*add_arg(t_cmd *cmd, char *arg)
{
	t_larg	*new_arg;
	t_larg	*tmp;

	if (cmd == NULL)
		return (NULL);
	if (arg == NULL)
		return (cmd->arg);
	new_arg = larg_init();
	new_arg->arg = ft_strdup(arg);
	tmp = cmd->arg;
	if (tmp == NULL)
		return (new_arg);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_arg;
	return (cmd->arg);
}
