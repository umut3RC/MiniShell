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

void	pwd(t_cmd cmd)
{
	char	*cwd;

	cwd = NULL;
	if (cmd.command)
	{
		exit_status(256, 0, "too many arguments\n");
		return ;
	}
	cwd = getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	free(cwd);
}
