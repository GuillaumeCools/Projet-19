/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:13 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 14:10:25 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

void	ft_num_to_hex(int n, int fd)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 16)
		ft_num_to_hex(n / 16, fd);
	ft_putchar_fd(hex_base[n % 16], fd);
}
