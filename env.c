/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 07:26:45 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/28 07:26:45 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"


static int		display_help(void)
{
	ft_putstr("env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n");
	ft_putstr("Set each NAME to VALUE in the environment and run COMMAND.\n");
	ft_putstr("\n");
	ft_putstr("  -i, --ignore-environment  start with an empty environment\n");
	ft_putstr("  -0, --null           end each output line with 0 byte");
	ft_putstr(" rather than newline\n");
	ft_putstr("  -u, --unset=NAME     remove variable from the environment\n");
	ft_putstr("      --help     display this help and exit\n");
	ft_putstr("      --version  output version information and exit\n");
	ft_putstr("\n");
	ft_putstr("A mere - implies -i.  If no COMMAND, print the ");
	ft_putstr("resulting environment.\n");
	return (0);
}


static int		display_version(void)
{
	ft_putstr("env implemented by nvan-hou verion 1.0\n");
	return (0);
}


static void	display_env(char to_print, char **envp)
{
	if (envp == NULL)
		return ;
		while (*envp != NULL)
	{
		ft_putstr(*envp);
		ft_putchar(to_print);
		envp++;
	}
	return ;
}


int			builtin_env(t_cmd *cmd,char **envp)
{

	return (res);
}
