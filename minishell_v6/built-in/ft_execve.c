/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/18 10:09:33 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*update_cmd(char *cmd)
{
	char	*ret;
	char	*path;

	if (ft_strchr2(cmd, '/'))
	{
		ret = ft_strdup(cmd);
		return (ret);
	}
	path = where(cmd);
	if (!path)
		return (NULL);
	else
	{
		ret = ft_strjoin2(path, "/");
		ret = ft_strjoin2(ret, cmd);
	}
	return (ret);
}

char	**join_cmd(char *cmd, t_list *lst)
{
	char	**str;
	int		j;
	int		quote_type;

	j = 1;
	quote_type = first_quote(cmd);
	str = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 2));
	str[0] = update_cmd(clear_char(to_lower_str(cmd), quote_type));
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	while (lst)
	{
		if (ft_strchr2(lst->content, 34) || ft_strchr2(lst->content, 39))
			lst->content = clear_char(lst->content, first_quote(lst->content));
		str[j++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	str[j] = NULL;
	return (str);
}

int	ft_execve(t_cmd cmd)
{
	int		pid;
	char	**arg;
	int		ret;

	ret = 0;
	arg = join_cmd(cmd.cmd, cmd.command);
	if (!arg)
		return (exit_status(256 * 127, 0, "command not found\n"));
	pid = fork();
	if (pid == 0)
	{
		if (execve(arg[0], arg, g_environ) == -1)
		{
			perror("");
			exit(1);
		}
		exit(0);
	}
	waitpid(pid, &ret, 0);
	ft_free_double(arg);
	return (exit_status(ret, 0, NULL));
}
