/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:53:22 by gcools            #+#    #+#             */
/*   Updated: 2023/11/28 16:17:04 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_temp(char *buf, char *temp, int fd)
{
	char		*second_temp;
	int			i;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (ft_free(temp), NULL);
	while (!ft_strchr(buf, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0)
			break ;
		buf[BUFFER_SIZE] = '\0';
		second_temp = ft_strjoin(temp, buf);
		ft_free (temp);
		temp = second_temp;
		if (temp == NULL)
			return (ft_free (buf), NULL);
	}
	//if (ft_strlen(buf) < 1)
	//	return (ft_free(buf), ft_free(temp), NULL);
	return (ft_free(buf), temp);
}

char	*ft_create_final(char *temp)
{
	char	*final;
	int		y;

	y = 0;
	if (!temp)
		return (NULL);
	if (!temp[y])
		return (ft_free(temp), NULL);
	final = ft_calloc((ft_count(temp) + 1), sizeof(char));
	if (!final)
		return (ft_free(temp), NULL);
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
	if (temp[i - 1] != '\n')
		return (ft_free(temp), NULL);
	swap = ft_calloc((ft_strlen(temp) - ft_strlen(final) + 1), sizeof(char));
	if (!swap)
		return (ft_free(temp), ft_free(final), NULL);
	while (temp[i])
	{
		swap[y] = temp[i];
		i++;
		y++;
	}
	swap[y] = '\0';
	return (ft_free(temp), swap);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*temp;
	char		*final;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = NULL;
	if (temp == NULL)
	{
		temp = ft_calloc(1, 1);
		if (!temp)
			return (NULL);
	}
	temp = ft_create_temp(buf, temp, fd);
	if (temp == NULL)
		return (NULL);
	final = ft_create_final(temp);
	if (final == NULL)
		return (NULL);
	temp = ft_create_swap(temp, final);
//	printf("%p", final);
	return (final);
}

void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open("fichier.txt", O_RDONLY);
	while (i < 1)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		ft_free (str);
		i++;
	}
//	system("leaks a.out");
	return (0);
}