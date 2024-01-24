/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:17:18 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/10/23 12:08:13 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*final;
	int		y;
	int		i;

	i = 0;
	y = ft_strlen(s);
	final = malloc((y + 1) * sizeof(char));
	if (final == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
/*
int	main(void)
{
	char *s = "test";

	printf("%s\n", ft_strdup(s));
	return (0);
}
*/