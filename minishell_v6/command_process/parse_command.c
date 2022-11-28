/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/15 17:54:36 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	word_count(char *str, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && !quote_state(str, i))
			ret++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (ret);
}

int	cut_str(char *dst, char **src, char c)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		if (dst[i] == c && !quote_state(dst, i))
			break ;
		i++;
	}
	*src = ft_substr(dst, 0, i);
	return (i);
}

char	**split2(char *str, char c)
{
	int		i;
	int		len;
	char	**ret;
	int		ret_index;

	len = -1;
	ret_index = -1;
	i = 0;
	ret = malloc(sizeof(char *) * (word_count(str, c) + 1));
	while (++len < word_count(str, c))
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != c)
			i += cut_str(&str[i], &ret[++ret_index], c);
	}
	ret[++ret_index] = NULL;
	return (ret);
}
