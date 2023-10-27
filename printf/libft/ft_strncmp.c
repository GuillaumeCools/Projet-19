/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:25:23 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/10/24 13:27:14 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (s1[i] && s2[i] && i < size && s1[i] == s2[i])
	{
		i++;
	}
	if (i == size)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char *s1 = "abcdef";
	char *s2 = "abc\375xx";
	int	size;

	size = 5;
	printf("%d\n", ft_strncmp(s1, s2, size));
	return (0);
}
*/
