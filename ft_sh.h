/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 06:00:54 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/27 06:00:54 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <stdlib.h>


typedef struct	s_cmd	s_cmd;
typedef struct	s_lopt	t_lopt;
typedef struct	s_larg	t_larg;

struct			s_cmd;
{
		char	*name;
		t_lopt	*opt;
		t_larg	*arg;
};

struct			s_lopt
{
		char	*opt;
		t_lopt	*next;
};

struct			s_larg
{
		char	*arg;
		t_arg	*next;
};


/*
** basic list operation func
** -------------------------
** init.c - add.c
*/
t_cmd	*cmd_init(void);
t_lopt	*lopt_init(void);
t_larg	*larg_init(void);
t_lopt	*add_opt(t_cmd *cmd, char *opt);
t_larg	*add_arg(t_cmd *cmd, char *arg);
/*
** main func
** -----------
** parse_cmd.c
*/
t_cmd	*parse_cmd(char *buf);


#endif /* !FT_SH_H */
