/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/17 15:47:05 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**env_2(char **env, int index)
{
	int		i;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	while (env[i])
		i++;
	tmp = ft_calloc(i, sizeof(char *));
	i = 0;
	while (env[i])
	{
		if (index != i)
		{
			tmp[k] = ft_strdup(env[i]);
			k++;
		}
		i++;
	}
	ft_free_double(g_environ);
	return (tmp);
}

void	free_env(char *arg)
{
	char	**tmp;
	int		i;

	i = 0;
	while (g_environ[i])
	{
		tmp = split2(g_environ[i], '=');
		if (ft_strstr(tmp[0], arg))
		{
			g_environ = env_2(g_environ, i);
			free(tmp[0]);
			free(tmp[1]);
			free(tmp);
			break ;
		}
		i++;
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
	}
}
