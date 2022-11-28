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

void	exit_f(t_cmd cmd)
{
	if (cmd.command)
	{
		exit_status(256, 0, "too many arguments\n");
		return ;
	}
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
