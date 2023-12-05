/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:40 by gcools            #+#    #+#             */
/*   Updated: 2023/11/16 14:54:15 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		lenght;
	char	*final;

	if (!s || !f)
		return (NULL);
	lenght = ft_strlen(s);
	i = 0;
	final = malloc(lenght * sizeof(char) + 1);
	if (!final)
		return (NULL);
	while (i < lenght)
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
