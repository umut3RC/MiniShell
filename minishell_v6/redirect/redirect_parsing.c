/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/15 17:49:15 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	red_count(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '<' || str[i] == '>'))
			i++;
		if (str[i] && !quote_state(str, i))
			ret++;
		while (str[i] && (str[i] != '<' && str[i] != '>'))
			i++;
	}
	return (ret);
}

int	cut_red(char *dst, char **src)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		if ((dst[i] == '<' || dst[i] == '>') && !quote_state(dst, i))
			break ;
		i++;
	}
	*src = ft_substr(dst, 0, i);
	return (i);
}

char	**redirect_split(char *str)
{
	char	**ret;
	int		i;
	int		ret_index;
	int		len;

	i = 0;
	ret_index = -1;
	len = -1;
	ret = malloc(sizeof(char *) * (red_count(str) + 1));
	while (++len < red_count(str))
	{
		while (str[i] && (str[i] == '<' || str[i] == '>'))
			i++;
		if (str[i] != '<' && str[i] != '>')
			i += cut_red(&str[i], &ret[++ret_index]);
	}
	ret[++ret_index] = NULL;
	return (ret);
}

char	**join_redirect(char **cmd)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (cmd[i])
	{
		j = 1;
		temp = split2(cmd[i], 32);
		while (temp[j])
		{
			cmd[0] = ft_strjoin2(cmd[0], " ");
			cmd[0] = ft_strjoin2(cmd[0], temp[j]);
			free(cmd[i]);
			cmd[i] = ft_strdup(temp[0]);
			j++;
		}
		ft_free_double(temp);
		i++;
	}
	return (cmd);
}

char	**redirect_delimiter(char *cmd)
{
	int		i;
	int		j;
	int		len;
	int		count;
	char	**str;

	str = malloc(sizeof(char *) * red_count(cmd));
	i = 0;
	len = -1;
	count = -1;
	while (++len < red_count(cmd))
	{
		while (cmd[i] && (cmd[i] != '<' && cmd[i] != '>'))
			i++;
		j = i;
		while (cmd[j] && (cmd[j] == '>' || cmd[j] == '<'))
			j++;
		if (cmd[i] == '>' || cmd[i] == '<')
			str[++count] = ft_substr(cmd, i, j - i);
		i = j;
	}
	str[++count] = NULL;
	return (str);
}
