/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/29 14:46:21 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	where_env_dolar_upgrade(char *s2)
{
	int		i;
	char	**env;
	char	*cwd;
	char	*tmp;

	cwd = NULL;
	cwd = getcwd(cwd, sizeof(cwd));
	i = 0;
	while (g_environ[i])
	{
		env = split2(g_environ[i], '=');
		if (ft_strstr(env[0], s2))
		{
			free(g_environ[i]);
			tmp = ft_strjoin(s2, "=");
			g_environ [i] = ft_strjoin(tmp, cwd);
			free(tmp);
		}
		ft_free_double(env);
		i++;
	}
	free(cwd);
}

char	*where_env_dolar(char *s2)
{
	int		i;
	char	**env;

	i = 0;
	while (g_environ[i])
	{
		env = split2(g_environ[i], '=');
		if (ft_strstr(env[0], s2))
		{
			free(env[0]);
			free(env);
			return (env[1]);
		}
		ft_free_double(env);
		i++;
	}
	return (NULL);
}

void	dolar_sign_con(char *temp, char *tmp)
{
	write(STDOUT_FILENO, tmp, ft_strlen(tmp));
	free(temp);
	free(tmp);
}

int	dolar_sign(char *str, int i)
{
	char	*temp;
	char	*tmp;

	temp = NULL;
	if (str[i + 1] == 32)
		return (-1);
	while (str[++i])
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
			break ;
	}
	if (str[i] == '?')
		return (exit_status(i, 1, NULL) + 1);
	temp = ft_substr(str, 0, i);
	tmp = where_env_dolar(&temp[1]);
	if (tmp == NULL)
	{
		free(tmp);
		free(temp);
		return (i);
	}
	dolar_sign_con(temp, tmp);
	return (i);
}

void	print_all(char *str, int quote)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(str);
	temp = clear_char(temp, quote);
	while (temp[i] != '\0')
	{
		if (temp[i + 1] && temp[i] == '$'
			&& quote != 39 && temp[i + 1] != 32)
			i += dolar_sign(&temp[i], 0);
		else
		{
			write(STDOUT_FILENO, &temp[i], 1);
			i++;
		}
	}
	free(temp);
}
