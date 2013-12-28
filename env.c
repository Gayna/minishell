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


static int		env_h_v(int help)
{
	if (help == FIRST_TRUE)
		return (display_help());
	return (display_version());
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


int			builtin_env(t_lopt	*opt,
							t_larg	*arg,
							char	**envp)
{
	t_env_opt	e_opt;
	char		to_print;
	t_cmd		*to_exec;
	t_builtin	*bi;
	int		res;

	res = 0;
	e_opt = e_opt_init(opt, &e_opt);
	envp = (e_opt->i == TRUE)? NULL : envp;
	to_print = (e_opt->0 == TRUE)? '\0' : '\n';
	if (e_opt->help != FALSE || e_opt->verion != FALSE)
		return (env_h_v(e_opt->help))
	if (e_opt->set == TRUE || e_opt->unset == TRUE)
		env_set_unset(opt, arg, envp);
	display_env(to_print, envp);
	if (arg != NULL)
	{
		to_exec = parse_cmd(arg_to_str(arg));
		bi = builtin_init();
		res = exec_cmd(to_exec, bi, envp);
		destroy_cmd(cmd);
		destroy_bi(bi);
	}
	return (res);
}
