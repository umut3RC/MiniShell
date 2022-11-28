/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/09/11 17:06:34 by eryilmaz         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	right_redirect(char *file)
{
	int	fd;

	fd = open_file(file);
	if (fd > 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (exit_status(fd, 0, NULL));
}

int	single_right_redirect(char *file)
{
	int		ret;
	char	*temp;

	temp = ft_strdup(file);
	temp = clear_char(temp, 32);
	clear_file(temp);
	ret = right_redirect(temp);
	free(temp);
	return (exit_status(ret, 0, NULL));
}

int	double_right_redirect(char *file)
{
	int		ret;
	char	*temp;

	temp = ft_strdup(file);
	temp = clear_char(temp, 32);
	ret = right_redirect(temp);
	free(temp);
	return (exit_status(ret, 0, NULL));
}
