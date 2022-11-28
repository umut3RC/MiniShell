/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:46:29 by uercan            #+#    #+#             */
/*   Updated: 2022/10/29 14:48:06 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_null(char *s1, char *s2, int i, int j)
{
	int		a;
	char	*s3;

	a = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
		a = 1;
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		s3[i + j] = s2[j];
	s3[i + j] = 0;
	if (a == 1)
		free(s1);
	return (s3);
}
