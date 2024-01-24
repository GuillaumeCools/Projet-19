/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_hex_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:13 by gcools            #+#    #+#             */
/*   Updated: 2023/11/07 11:59:51 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	ft_num_to_hex_return(unsigned int n, int fd)
{
	int		total;
	char	*hex_base;

	total = ft_intlen_hex(n);
	hex_base = "0123456789abcdef";
	if (n >= 16)
	{
		if (ft_num_to_hex_return(n / 16, fd) == -1)
			return (-1);
	}
	if (ft_putchar_return(hex_base[n % 16], fd) == -1)
		return (-1);
	return (total);
}
