/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_hex_up_return.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:22 by gcools            #+#    #+#             */
/*   Updated: 2023/11/06 16:59:10 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_num_to_hex_up_return(unsigned int n, int fd)
{
	int		total;
	char	*hex_base;

	total = ft_intlen_hex(n);
	hex_base = "0123456789ABCDEF";
	if (n >= 16)
		ft_num_to_hex_up_return(n / 16, fd);
	if (ft_putchar_return(hex_base[n % 16], fd) == -1)
		return (-1);
	return (total);
}
