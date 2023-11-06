/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:36 by gcools            #+#    #+#             */
/*   Updated: 2023/11/06 15:03:24 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_return(int n, int fd)
{
	int	total;

	total = ft_intlen_original(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar_return('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_return(n / 10, fd);
	}
	ft_putchar_return((n % 10) + '0', fd);
	return (total);
}
