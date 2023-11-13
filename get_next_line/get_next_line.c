/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:53:22 by gcools            #+#    #+#             */
/*   Updated: 2023/11/13 16:30:16 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
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

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*temp;
	char		*second_temp;
	int			i;
	int			y;

	y = 0;
	if (temp == NULL)
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
	}
	i = ft_strlen(temp);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	second_temp = ft_strjoin(temp, buf);
	free (temp);
	temp = second_temp;
	if (temp == NULL)
		return (NULL);
	while (y < BUFFER_SIZE)
	{
		temp[i] = buf[y];
		i++;
		y++;
	}
	if (ft_check(temp) != 1)
		return (get_next_line(fd));
	else
		return (temp);
}

int	main(void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
