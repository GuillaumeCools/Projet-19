/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:31:08 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/11/13 13:06:53 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	while (dest[y] && y < size)
	{
		y++;
	}
	while (src[i] && y + i + 1 < size)
	{
		dest[y + i] = src[i];
		i++;
	}
	if (y + i < size)
		dest[y + i] = '\0';
	return (y + ft_strlen(src));
}
/*
int	main(void)
{
	char	*dest = NULL;
	const 	char *src = "test";
	int		size = 0;
	
	printf("%zu\n", ft_strlcat(dest, src, size));
	//printf("%zu\n", strlcat(dest, src, size));
	return (0);
}
*/
