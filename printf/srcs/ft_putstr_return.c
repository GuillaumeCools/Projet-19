/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:48:50 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/11/06 17:06:15 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_return(char *s, int fd)
{
	int	i;
	int	total;

	if (s == NULL)
	{
		ft_putstr_return("(null)", 1);
		return (6);
	}
	total = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (ft_putchar_return(s[i], fd) == -1)
			return (-1);
		i++;
	}
	return (total);
}
