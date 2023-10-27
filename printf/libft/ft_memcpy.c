/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:52:24 by gcools            #+#    #+#             */
/*   Updated: 2023/10/23 15:31:15 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*final;
	char	*s;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	final = dest;
	s = (char *)src;
	while (n > 0)
	{
		final[i] = s[i];
		i++;
		n--;
	}
	return (final);
}
/*
int	main(void)
{
	char	src[] = "bonjour";
	char	dest[50] = "test";
	int		n;

	n = 3;
	printf("%s\n", ft_memcpy(dest, src, n));
	return (0);
}
*/
