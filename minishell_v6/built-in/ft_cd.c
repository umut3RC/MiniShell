/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/29 14:45:54 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*sequence(char **temp, char *en, char *ret)
{
	int	i;

	i = -1;
	while (temp[++i])
	{
		if (temp[i][0] == '$')
		{
			en = where_env_dolar(&temp[i][1]);
			ret = ft_strjoin2(ret, en);
			free(en);
			if (!ret)
			{
				ft_free_double(temp);
				return (NULL);
			}
		}
		if (temp[i + 1])
			ret = ft_strjoin(ret, "/");
	}
	ft_free_double(temp);
	return (ret);
}

int	ft_cd_con(t_cmd cmd)
{
	cmd.command->content = clear_char(cmd.command->content,
			first_quote(cmd.command->content));
	if (access(cmd.command->content, F_OK) != -1)
	{
		where_env_dolar_upgrade("OLDPWD");
		chdir(cmd.command->content);
		where_env_dolar_upgrade("PWD");
	}
	else
	{
		exit_status(256, 0, NULL);
		perror("");
		return (1);
	}
	return (0);
}

void	cd(t_cmd cmd)
{
	char	*temp;
	char	*en;

	temp = NULL;
	if (cmd.command != NULL && ft_strchr2(cmd.command->content, '$'))
	{
		temp = ft_strdup(cmd.command->content);
		free(cmd.command->content);
		cmd.command->content = sequence(split2(temp, '/'), NULL, NULL);
		free(temp);
	}
	if (cmd.command == NULL || cmd.command->content == NULL)
	{
		en = where_env_dolar("HOME");
		where_env_dolar_upgrade("OLDPWD");
		chdir(en);
		where_env_dolar_upgrade("PWD");
		free(en);
	}
	else
	{
		if (ft_cd_con(cmd) == 1)
			return ;
	}
	exit_status(0, 0, NULL);
}
