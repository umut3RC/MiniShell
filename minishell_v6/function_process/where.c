/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/17 15:11:47 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_path(char *path, char *cmd)
{
	struct dirent	*de;
	DIR				*dir;

	dir = opendir(path);
	if (dir == NULL)
	{
		printf("Could not open current directory");
		return (0);
	}
	de = readdir(dir);
	while (de)
	{
		if (ft_strstr(de->d_name, cmd))
		{
			closedir(dir);
			return (1);
		}
		de = readdir(dir);
	}
	closedir(dir);
	return (0);
}

char	*where(char *cmd)
{
	char	**temp;
	char	*ret;
	int		i;

	ret = NULL;
	if (where_env("PATH") != -1)
		temp = ft_split(getenv("PATH"), ':');
	else
		return (NULL);
	i = -1;
	while (temp[++i])
	{
		if (find_path(temp[i], cmd))
		{
			ret = ft_strdup(temp[i]);
			break ;
		}
	}
	ft_free_double(temp);
	return (ret);
}
