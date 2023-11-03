/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:22 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 14:10:21 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_num_to_hex_up(int n, int fd)
{
	char	*hex_base;

	hex_base = "0123456789ABCDEF";
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
		ft_num_to_hex_up(n / 16, fd);
	ft_putchar_fd(hex_base[n % 16], fd);
}
