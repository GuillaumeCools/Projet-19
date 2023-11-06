/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:49:20 by gcools            #+#    #+#             */
/*   Updated: 2023/11/04 00:01:10 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t size)
{
	size_t	i;
	char	*final;

	final = b;
	i = 0;
	while (i < size)
	{
		final[i] = c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char	b[] = "Bonjour";
	int		c;
	int		size;

	c = '/';
	size = 3;
	printf("%s\n", ft_memset(b, c, size));
	return (0);
}
*/
