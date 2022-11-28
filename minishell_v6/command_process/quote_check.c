/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/15 18:05:20 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quote_state(char *str, int pos)
{
	int	ret;
	int	i;
	int	quote;

	ret = 0;
	i = 0;
	quote = 0;
	while (str[i] && i < pos)
	{
		if (!quote && (str[i] == 34 || str[i] == 39))
			quote = str[i];
		if (quote == str[i] && ret == 0)
			ret = 1;
		else if (quote == str[i] && ret == 1)
			ret = 0;
		i++;
	}
	return (ret);
}

int	first_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 34 || str[i] == 39))
			return (str[i]);
		i++;
	}
	return (0);
}

int	char_count(char *str, char c)
{
	int	i;
	int	ret;

	if (!str)
		return (0);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == c && !quote_state(str, i))
			ret++;
		i++;
	}
	return (ret);
}

char	*clear_char(char *str, char c)
{
	int		i;
	int		j;
	char	*ret;
	int		len;
	int		quote_len;

	quote_len = char_count(str, c);
	len = ft_strlen(str);
	ret = (char *)ft_calloc(sizeof(char), (len - quote_len) + 1);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != c)
			ret[j++] = str[i];
	}
	free(str);
	return (ret);
}
