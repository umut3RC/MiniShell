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

int	lst_find(t_list **lst, void *data)
{
	int	i;
	int	size;

	size = ft_lstsize(*lst);
	i = 0;
	if (!*lst)
		return (0);
	while (*lst)
	{
		if (ft_strstr((*lst)->content, data)
			|| !ft_strncmp((*lst)->content, data, ft_strlen(data)))
			(*lst) = (*lst)->next;
		else
			break ;
		i++;
	}
	if (size == i)
		return (1);
	return (0);
}

void	add_to_list(char **temp, t_list **cmd)
{
	int	i;

	i = 1;
	while (temp[i])
		ft_lstadd_back(cmd, ft_lstnew(ft_strdup(temp[i++])));
}

void	lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
}
