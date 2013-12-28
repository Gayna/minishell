/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 05:47:23 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/27 05:47:23 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "ft_sh.h"


static void	display_usage(char *bin_name)
{
	ft_pustr(bin_name);
	ft_pustr(": this bin does not take any arguments\nproceeding...\n");
	return ;
}

int			main(int	argc,
					 char	**argv,
					 char	**envp)
{
	int		res;
	t_builtin	bi[NBR_FUNC];
	t_cmd		*cmd;
	char		*buff;

	res = 0;
	if (argc > 1)
		display_usage(argv[1]);
	bi = builtin_init();
	while (42)
	{
		write(1, "$> ", 3);
		while ((buf = get_next_cmd()) != NULL)
		{
			cmd = parse_cmd(buf);
			res = exec_cmd(cmd, bi, envp);
			destroy_cmd(cmd);
			free(buf);
			buf = NULL;
		}
	}
	return (res);
}
