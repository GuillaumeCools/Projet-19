/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:32:28 by gcools            #+#    #+#             */
/*   Updated: 2023/10/26 10:29:14 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if ((size - start) < len)
		len = size - start;
	final = malloc(len * sizeof(char) + 1);
	if (!final)
		return (NULL);
	i = 0;
	while (i < len)
	{
		final[i] = s[start + i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
/*
int	main(void)
{
	char	s[] = "";
	int		start;
	size_t	len;

	start = 1;
	len = 1;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}
*/
