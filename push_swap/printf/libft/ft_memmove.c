/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:32 by gcools            #+#    #+#             */
/*   Updated: 2023/10/24 11:53:43 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t					i;
	unsigned char			*final;
	const unsigned char		*s;

	if (!dest && !src)
		return (NULL);
	final = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (final < s)
	{
		i = 0;
		while (i < size)
		{
			final[i] = s[i];
			i++;
		}
		return (dest);
	}
	i = size;
	while (i > 0)
	{
		final[i - 1] = s[i - 1];
		i--;
	}
	return (dest);
}
/*
int	main(void)
{
	void	*src = "123456";
	void	*dest;
	dest = malloc(1000);
	int		size;

	size = 4;
	printf("%s\n", ft_memmove(dest, src, size));
	return (0);
}
*/
