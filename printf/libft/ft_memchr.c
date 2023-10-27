/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:34:02 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/10/24 13:41:48 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned char	ch;
	unsigned char	*str;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (size > 0)
	{
		if (*str == ch)
			return (str);
		str++;
		size--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*s = "test";
	int		c;
	int		size;

	c = 'e';
	size = 3;
	printf("%s\n", ft_memchr(s, c, size));
	return (0);
}
*/
