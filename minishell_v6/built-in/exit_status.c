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

int	exit_status(int status, int flag, char *message)
{
	static int	ret;
	char		*ret2;

	ret2 = NULL;
	if (flag == 1)
	{
		ret2 = ft_itoa(ret / 256);
		write(STDOUT_FILENO, ret2, ft_strlen(ret2));
		free(ret2);
	}
	if (message)
		write(STDERR_FILENO, message, ft_strlen(message));
	ret = status;
	return (ret);
}
