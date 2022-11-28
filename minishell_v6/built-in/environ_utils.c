/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/17 16:14:18 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	where_env(char *s2)
{
	int		i;
	char	**temp;
	char	**env;

	i = 0;
	temp = split2(s2, '=');
	while (g_environ[i])
	{
		env = split2(g_environ[i], '=');
		if (ft_strstr(env[0], temp[0]))
		{
			ft_free_double(env);
			ft_free_double(temp);
			return (i);
		}
		ft_free_double(env);
		i++;
	}
	ft_free_double(temp);
	return (-1);
}

int	check_env_arg(t_cmd cmd)
{
	char	**arg;

	arg = split2(cmd.command->content, '=');
	if (!arg[0])
	{
		free((void *)arg);
		return (exit_status(256, 0, "not a valid identifier\n"));
	}
	else if ((!is_alnum(arg[0]) || ft_isdigit(arg[0][0])))
	{
		ft_free_double(arg);
		return (exit_status(256, 0, "not a valid identifier\n"));
	}
	ft_free_double(arg);
	return (exit_status(0, 0, NULL));
}

void	add_env(char *env, int env_index)
{
	int		count;

	count = ft_double_strlen(g_environ);
	if (env_index < 0)
	{
		g_environ = ft_realloc(g_environ, sizeof(char *) * (count + 2));
		g_environ[count] = ft_strdup(env);
		g_environ[count + 1] = NULL;
	}
	else
	{
		free(g_environ[env_index]);
		g_environ[env_index] = ft_strdup(env);
	}
}

char	**env_1(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i])
		i++;
	tmp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	return (tmp);
}
