/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:53:13 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/10/23 12:08:59 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *all, const char *key, size_t size)
{
	size_t	i;
	size_t	y;

	if (!*key)
		return ((char *)all);
	i = 0;
	while (all[i] && i < size)
	{
		y = 0;
		while (all[i + y] && key[y] && i + y < size && all[i + y] == key[y])
		{
			y++;
		}
		if (!key[y])
		{
			return ((char *)&all[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *all = "test";
	char *key = "e";
	int size;

	size = 3;
	printf("%s\n", ft_strnstr(all, key, size));
	return (0);
}
*/
