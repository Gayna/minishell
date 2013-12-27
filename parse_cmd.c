/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-hou <nvan-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 06:46:06 by nvan-hou          #+#    #+#             */
/*   Updated: 2013/12/27 06:46:06 by nvan-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sh.h"

static size_t	get_offset(char *buf, size_t pos)
{
	size_t	offset;

	offset = pos;
	while (buf[offset] != ' '
		   && buf[offset] != '\t'
		   && buf[offset] != '\0')
		offset++;
	return (offset);
}

static char	*get_next_token(char *buf)
{
	static size_t	pos = 0;
	char			*token;
	size_t			it;
	size_t			offset;

	it = pos;
	if (buf == NULL)
		return (NULL);
	while (buf[pos] == ' ' || buf[pos] == '\t')
		pos++;
	if (buf[pos] == '\0')
		return (NULL);
	offset = get_offset(buf, pos);
	token = (char *)malloc(sizeof(char) * (offset + 1));
	while (it < offset)
	{
		token[it - pos] = buf[it];
		it++;
	}
	token[it - pos] = '\0';
	pos = (pos == offset)? 0 : offset;
	return (token);
}


t_cmd			*parse_cmd(char *buf)
{
	char	*tmp;
	t_cmd	*cmd;
	size_t	size;

	if (buf == NULL)
		return (NULL);
	cmd = cmd_init();
	cmd->name = get_next_token(buf);
	while ((tmp = get_next_token(buf + offset)) != NULL)
	{
		if (tmp[0] == '-')
			cmd->opt = add_lopt(cmd, tmp);
		else
			cmd->arg = add_argt(cmd, tmp);
	}
	return (cmd);
}
