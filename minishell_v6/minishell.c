/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/29 14:44:03 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rl_gets(char *str, const char *prompt)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	str = readline(prompt);
	if (str && *str)
		add_history(str);
	return (str);
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

char	*name_assigment(void)
{
	char	*tmp;
	char	*user;

	if (getenv("LOGNAME") != NULL)
		tmp = getenv("LOGNAME");
	else
		tmp = "USER";
	user = ft_strjoin("\033[0;36m", tmp);
	user = ft_strjoin2(user, "@miniminiminishell");
	user = ft_strjoin2(user, " >\e[0m ");
	return (user);
}

void	loop(void)
{
	char	*input;
	char	*user;

	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	input = NULL;
	user = name_assigment();
	file_process();
	while (1)
	{
		input = rl_gets(input, user);
		if (!input)
		{
			write(2, "exit\n", 6);
			exit(0);
		}
		else if (check_syntax(input))
			continue ;
		heredoc(input);
		parse_string(input);
	}
}

int	main(int index __attribute((unused)),
	char **str __attribute((unused)), char **env_m)
{
	g_environ = env_1(env_m);
	loop();
	return (0);
}
