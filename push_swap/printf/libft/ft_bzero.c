/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:15:13 by gcools            #+#    #+#             */
/*   Updated: 2023/10/23 12:05:46 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int	main(void)
{
	char	b[] = "Bonjour";
	int		size;

	size = 3;
	printf("%s\n", ft_memset(b, size));
	return (0);
}
*/
