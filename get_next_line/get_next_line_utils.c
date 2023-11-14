/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:04:57 by gcools            #+#    #+#             */
/*   Updated: 2023/11/14 16:11:02 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		i++;
	}
	return (i);
}

int	ft_check(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if ('\n' == temp[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && charset[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		length_total;
	int		i;
	int		y;

	i = 0;
	y = 0;
	length_total = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(length_total * sizeof(char) + 1);
	if (!final)
		return (NULL);
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		final[i] = s2[y];
		i++;
		y++;
	}
	final[i] = '\0';
	return (final);
}
