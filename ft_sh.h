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


typedef struct	s_cmd	t_cmd;
typedef struct	s_larg	t_larg;

struct			s_cmd
{
		char	*name;
		t_lopt	*opt;
		t_larg	*arg;
		int	last_return_val;
};

struct			s_larg
{
		char	*arg;
		t_larg	*next;
};

typedef int	(*t_fptr)(t_cmd *, char **);
typedef struct	s_builtin
{
		char	name[32];
		t_fptr	func;
}				t_builtin;

# define NBR_FUNC 5
# define TRUE 1
# define FALSE 0
# define ERR -1
# define FIRST_TRUE 3
# define NULL_CMD 4
# define MAX_PATH_SIZE 1024
/*
** basic list operation func
** --------------------------
** init.c - add.c - destroy.c
*/
void	builtin_init(t_builtin *bi);
t_cmd	*cmd_init(void);
t_larg	*larg_init(void);
t_larg	*add_arg(t_cmd *cmd, char *arg);
void	destroy_cmd(t_cmd *cmd);
void	destroy_larg(t_larg *arg);


/*
** builtin
** ----------------------
** env.c - exit.c
*/
int	builtin_env(t_cmd *cmd, char **envp);
int	builtin_exit(t_cmd *cmd, char **envp);

/*
** main func
** -----------------------------------------
** parse_cmd.c - exec_cmd.c - get_next_cmd.c
*/
char	*get_next_cmd(void);
t_cmd	*parse_cmd(char *buf);
int	exec_cmd(t_cmd *cmd, t_builtin *bi, char **envp);

#endif /* !FT_SH_H */
