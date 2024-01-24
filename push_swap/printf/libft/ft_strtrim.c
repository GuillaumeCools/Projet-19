/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:31:06 by gcools            #+#    #+#             */
/*   Updated: 2023/10/26 11:53:00 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_checksep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*final;
	int		len;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_checksep(s1[start], (char *)set))
		start++;
	while (end > start && ft_checksep(s1[end], (char *)set))
		end--;
	len = end - start + 1;
	if (len <= 0)
		len = 0;
	final = malloc((len + 1) * sizeof(char));
	if (!final)
		return (NULL);
	i = -1;
	while (i++ < len - 1)
		final[i] = s1[start + i];
	final[i] = '\0';
	return (final);
}
/*
int	main(void)
{
	char	*s1 = "HelloWorld";
	char	*set = NULL;

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/
