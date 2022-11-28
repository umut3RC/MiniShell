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

void	ft_pipe(char **cmd, int count)
{
	int	**fd;
	int	*pid;
	int	i;

	pid = malloc(sizeof(int) * count + 1);
	i = -1;
	fd = ft_multiple_fd(count + 1);
	while (++i <= count)
	{
		pid[i] = ft_fork();
		if (pid[i] == 0)
		{
			if (i > 0)
				dup2(fd[i - 1][0], STDIN_FILENO);
			if (i != count)
				dup2(fd[i][1], STDOUT_FILENO);
			ft_multiple_close(fd, count + 1);
			parse_string(cmd[i]);
			exit(0);
		}
	}
	ft_multiple_close(fd, count + 1);
	multiple_waitpid(pid, count + 1);
	ft_free_int(fd, count + 1);
	free(pid);
}
