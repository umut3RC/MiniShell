/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/29 14:44:12 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		s1 = (char *)ft_calloc(sizeof(char), 1);
	str = (char *)ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_double_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	file_process(void)
{
	int		fd;
	char	*promt;

	promt = ft_strjoin(getenv("PWD"), "/redirect/.heredoc");
	if (!is_exist_file(promt))
	{
		fd = open(promt, O_CREAT, 0666);
		if (fd < 0)
		{
			perror("create : ");
		}
		close(fd);
	}
	free(promt);
	promt = ft_strjoin(getenv("PWD"), "/redirect/.no_such_file");
	if (!is_exist_file(promt))
	{
		fd = open(promt, O_CREAT, 0666);
		if (fd < 0)
		{
			perror("create : ");
		}
		close(fd);
	}
	free(promt);
}
