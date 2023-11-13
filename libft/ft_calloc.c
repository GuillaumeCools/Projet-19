/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:03:51 by gcools            #+#    #+#             */
/*   Updated: 2023/11/13 11:45:51 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	int		total;
	char	*str;

	if (size < 0)
		return (NULL);
	i = 0;
	total = count * size;
	str = malloc(total * sizeof(void));
	if (!str)
		return (NULL);
	while (i < total)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int		count;
	size_t	size;

	count = 3;
	size = 1500000;
	printf("%s\n", ft_calloc(count, size));
	printf("%s\n", calloc(count, size));
	return (0);
}
*/
