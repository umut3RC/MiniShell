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

int	determine_syntax(char *str, int i)
{
	if (str[i] == '<')
	{
		if (!check_right_r(i, str))
			return (exit_status(258 * 256, 0,
					"syntax error near unexpected token '<'\n"));
	}
	else if (str[i] == '>')
	{
		if (!check_right(i, str))
			return (exit_status(258 * 256, 0,
					"syntax error near unexpected token '>'\n"));
	}
	return (0);
}
