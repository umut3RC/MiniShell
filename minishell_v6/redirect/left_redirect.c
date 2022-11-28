/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/29 14:54:14 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	singel_left_redirect(char *file)
{
	int		fd;
	char	*temp;
	char	*promt;

	temp = ft_strtrim(file, " ");
	fd = open(temp, O_RDWR);
	if (fd < 0)
	{
		promt = ft_strjoin(getenv("PWD"), "/redirect/.no_such_file");
		perror(temp);
		free(temp);
		exit_status(fd, 0, NULL);
		fd = open(promt, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		free(promt);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (exit_status(fd, 0, NULL));
}

void	signal_for_rl2(int sign)
{
	if (sign == SIGINT)
	{
		printf("\r%c", 0);
		exit(0);
	}
}

static char	*heredoc_promt(char *eof, char *str, char *input, char *en)
{
	while (1)
	{
		signal(SIGINT, signal_for_rl2);
		input = readline(">");
		if (ft_strstr(input, eof))
			break ;
		if (ft_strchr2(input, '$'))
		{
			en = where_env_dolar(&input[1]);
			if (!en)
			{
				free(en);
				continue ;
			}
			input = ft_strjoin_null(en, "\n", 0, 0);
			free(en);
		}
		else
			input = ft_strjoin2(input, "\n");
		str = ft_strjoin2(str, input);
		free(input);
	}
	free(input);
	return (str);
}

int	double_left_redirect(char *eof)
{
	char	*str;
	char	*promt;
	int		fd;

	promt = ft_strjoin(getenv("PWD"), "/redirect/.heredoc");
	str = NULL;
	if (!eof || !ft_strlen(eof))
		return (exit_status(-1, 0, "syntax error\n"));
	eof = clear_char(eof, 32);
	fd = open_file(promt);
	clear_file(promt);
	str = heredoc_promt(eof, NULL, NULL, NULL);
	ft_putstr_fd(str, fd);
	close(fd);
	free(promt);
	return (exit_status(fd, 0, NULL));
}
