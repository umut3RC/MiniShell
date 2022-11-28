/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/17 15:47:05 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_cmd cmd)
{
	int	i;

	i = 0;
	if (cmd.command)
	{
		exit_status(256, 0, "with no options\n");
		return ;
	}
	while (g_environ[i])
		printf("%s\n", g_environ[i++]);
	exit_status(0, 0, NULL);
}

char	**ft_dub_dou(char **str)
{
	char			**return_val;
	unsigned int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return_val = malloc(sizeof(char *) * counter + 1);
	*(return_val + counter) = 0;
	counter = 0;
	while (str[counter])
	{
		return_val[counter] = ft_strdup(str[counter]);
		counter++;
	}
	return (return_val);
}

void	view_export(int i, int j)
{
	char	**g_environ2;
	char	*temp;

	g_environ2 = ft_dub_dou(g_environ);
	while (g_environ2[++i])
	{
		j = i;
		while (g_environ2[j])
		{
			if (ft_strncmp(g_environ2[i],
					g_environ2[j], ft_strlen(g_environ2[j])) > 0)
			{
				temp = g_environ2[i];
				g_environ2[i] = g_environ2[j];
				g_environ2[j] = temp;
			}
			j++;
		}
	}
	i = -1;
	while (g_environ2[++i])
		printf("declare -x %s\n", g_environ2[i]);
	ft_free_double(g_environ2);
	exit_status(0, 0, NULL);
}

void	export(t_cmd cmd)
{
	int	arg_index;

	if (!cmd.command)
	{
		view_export(-1, -1);
		return ;
	}
	while (cmd.command)
	{
		if (!check_env_arg(cmd))
		{
			arg_index = where_env(cmd.command->content);
			cmd.command->content = clear_char(cmd.command->content,
					first_quote(cmd.command->content));
			if (ft_strchr2(cmd.command->content, '='))
				add_env(cmd.command->content, arg_index);
		}
		cmd.command = cmd.command->next;
	}
	exit_status(0, 0, NULL);
}

void	unset(t_cmd cmd)
{
	while (cmd.command)
	{
		if (!is_alnum(cmd.command->content))
			exit_status(256, 0, "not a valid identifier\n");
		free_env(cmd.command->content);
		cmd.command = cmd.command->next;
	}
}
