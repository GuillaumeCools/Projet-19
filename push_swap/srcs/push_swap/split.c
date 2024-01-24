/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:42:21 by guillaumeco       #+#    #+#             */
/*   Updated: 2024/01/24 17:08:08 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char static	**ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int static	ft_tab_count(char const *s, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (s[0] == 0)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			y++;
			while (s[i] == c && s[i])
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		y++;
	return (y);
}

char static	*ft_create_word(char *s, char c)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char static	**ft_create_split(char c, char const *s, char **split)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			split[y] = ft_create_word((char *)&s[i], c);
			if (!split[y])
			{
				ft_free(split);
				return (NULL);
			}
			y++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	split[y] = NULL;
	return (split);
}

char	**split(char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_tab_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_create_split(c, s, split);
	if (!split)
		return (NULL);
	return (split);
}
