/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:16:42 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 14:10:29 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_putnbr_hex(uintptr_t n, int fd)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 16)
		ft_putnbr_hex(n / 16, fd);
	ft_putchar_fd(hex_base[n % 16], fd);
}
