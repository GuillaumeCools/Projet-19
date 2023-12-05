/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:03:51 by gcools            #+#    #+#             */
/*   Updated: 2023/11/14 11:27:33 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total;
	char		*str;

	i = 0;
	if (size == 0 || count == 0)
		return (malloc(0));
	total = count * size;
	if (total / count != size)
		return (NULL);
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

	count = 5;
	size = 0;
	printf("%s\n", ft_calloc(count, size));
	printf("%s\n", calloc(count, size));
	return (0);
}
*/
