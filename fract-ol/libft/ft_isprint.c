/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:03:51 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/10/23 12:06:37 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
int main(void)
{
	printf("%d\n", ft_isprint('t'));
	return (0);
}
*/