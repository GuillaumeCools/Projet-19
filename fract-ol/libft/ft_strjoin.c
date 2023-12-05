/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:19:44 by gcools            #+#    #+#             */
/*   Updated: 2023/11/16 14:53:45 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		length_total;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	length_total = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(length_total * sizeof(char) + 1);
	if (!final)
		return (NULL);
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[y])
		final[i++] = s2[y++];
	final[i] = '\0';
	return (final);
}
/*
int	main(void)
{
	char	*s1 = "test";
	char	*s2 = "moi";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
