/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:06:33 by eryilmaz          #+#    #+#             */
/*   Updated: 2022/10/17 16:02:38 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_option(t_list **lst)
{
	if (ft_strstr("-n", (*lst)->content))
	{
		lst_find(lst, "-n");
		return (1);
	}
	else
		return (0);
}

void	ft_echo(t_cmd cmd)
{
	int	new_line;
	int	quote;

	if (cmd.command)
		new_line = check_option(&cmd.command);
	if (!cmd.command)
	{
		exit_status(0, 0, NULL);
		printf("\n");
		return ;
	}
	while (cmd.command)
	{
		quote = first_quote(cmd.command->content);
		print_all(cmd.command->content, quote);
		if (cmd.command->next != NULL)
			write(STDOUT_FILENO, " ", 1);
		cmd.command = cmd.command->next;
	}
	if (new_line == 0)
		exit_status(0, 0, "\n");
}
