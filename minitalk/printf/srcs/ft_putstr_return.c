/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:48:50 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/11/07 11:58:32 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	ft_putstr_return(char *s, int fd)
{
	int	i;
	int	total;

	if (s == NULL)
	{
		if (ft_putstr_return("(null)", 1) == -1)
			return (-1);
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
