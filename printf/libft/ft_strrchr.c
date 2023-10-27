/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:04 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/10/24 13:09:14 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	char	*s = "teste";
	int		c;

	c = 't';
	printf("%s\n", ft_strrchr(s, c));
	return (0);
}
*/
