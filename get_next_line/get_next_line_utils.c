/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:04:57 by gcools            #+#    #+#             */
/*   Updated: 2023/11/29 13:50:47 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *charset)
{
	int	i;

	i = 0;
	if (charset == NULL)
		return (0);
	while (charset[i])
		i++;
	return (i);
}

int	ft_count(char *charset)
{
	int	i;

	i = 0;
	if (charset == NULL)
		return (0);
	while (charset[i] && charset[i] != '\n')
		i++;
	if (charset[i] == '\n')
		i++;
	return (i);
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
	final = ft_calloc((length_total + 1), sizeof(char));
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

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total;
	char		*str;

	i = 0;
	if (size == 0 || count == 0)
		return (malloc(0));
	total = count * size;
	if (total / count != size)
		return (NULL);
	str = malloc(total * sizeof(void));
	if (!str)
		return (NULL);
	while (i < total)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
