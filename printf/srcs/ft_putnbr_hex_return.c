/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:16:42 by gcools            #+#    #+#             */
/*   Updated: 2023/11/06 15:00:20 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_putnbr_hex_return(uintptr_t n, int fd)
{
	int		total;
	char	*hex_base;

	total = ft_intlen_hex(n);
	hex_base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex_return(n / 16, fd);
	ft_putchar_return(hex_base[n % 16], fd);
	return (total);
}
