/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:53:22 by gcools            #+#    #+#             */
/*   Updated: 2023/11/14 10:05:18 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

void	*ft_bzero(void *b, size_t size)
{
	size_t	i;
	char	*final;

	final = b;
	i = 0;
	while (i < size)
	{
		final[i] = '\0';
		i++;
	}
	return (b);
}

int	ft_count(char *charset)
{
	int	i;

	i = 0;
	while(charset[i] && charset[i] != '\n')
	{
		i++;
	}
	return (i + 1);
}

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
	char		*final;
	int			i;
	int			y;

	y = 0;
	if (temp == NULL) //initialise et malloc temp quand on rentre dans get_next_line pour la premiere fois
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
	}
	i = ft_strlen(temp);
	buf = malloc(BUFFER_SIZE); //malloc le buffer
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE); //remplis mon buffer
	second_temp = ft_strjoin(temp, buf); // malloc l addition des deux tailles (buffer + temp)
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
	if (ft_check(temp) != 1) // check si il y a un retour a la ligne
		return (get_next_line(fd));
	else
	{
		y = 0;
		i = 0;
		final = malloc(ft_count(temp) * sizeof(char));
		while (y < ft_count(temp))
		{
			final[y] = temp[y];
			y++;
		}
	}
	return (final);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	while (i < 2)
	{
		fd = open("fichier.txt", O_RDONLY);
		printf("%s\n", get_next_line(fd));
		i++;
	}
	return (0);
}
