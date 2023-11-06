/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:48:50 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/11/06 14:33:37 by gcools           ###   ########.fr       */
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
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (total);
}
