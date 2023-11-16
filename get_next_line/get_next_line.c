/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:53:22 by gcools            #+#    #+#             */
/*   Updated: 2023/11/15 15:02:13 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_temp(char *buf, char *temp, int fd)
{
	char		*second_temp;
	int			i;

	//pour verifier si on est deja arriver a la fin du fichier
	i = read(fd, buf, BUFFER_SIZE);
	if (i == 0)
		return (NULL);

	while (ft_check(temp) == 0)
	{
		buf = malloc(BUFFER_SIZE);
		if (!buf)
			return (NULL);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0)
			return (temp);
		buf[BUFFER_SIZE] = '\0';
		second_temp = ft_strjoin(temp, buf);
		free (temp);
		temp = second_temp;
		if (temp == NULL)
			return (NULL);
	}
	return (temp);
}

char	*ft_create_final(char *temp)
{
	char	*final;
	int		y;

	y = 0;
	final = malloc((ft_count(temp) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	while (y < ft_count(temp))
	{
		final[y] = temp[y];
		y++;
	}
	final[y] = '\0';
	return (final);
}

char	*ft_create_swap(char *temp, char *final)
{
	char	*swap;
	int		i;
	int		y;

	y = 0;
	i = ft_strlen(final);
	swap = malloc((ft_strlen(temp) - ft_strlen(final)) * sizeof(char));
	if (!swap)
		return (NULL);
	while (temp[i])
	{
		swap[y] = temp[i];
		i++;
		y++;
	}
	return (swap);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*temp;
	char		*final;
	char		*swap;

	buf = NULL;
	if (temp == NULL)
	{
		temp = malloc(1);
		if (!temp)
			return (NULL);
	}
	temp = ft_create_temp(buf, temp, fd);
	if (temp == NULL)
		return (NULL);
	final = ft_create_final(temp);
	if (final == NULL)
		return (NULL);
	swap = ft_create_swap(temp, final);
	if (swap == NULL)
		return (NULL);
	free(temp);
	temp = swap;
	return (final);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("fichier.txt", O_RDONLY);
	while (i < 8)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	return (0);
}
