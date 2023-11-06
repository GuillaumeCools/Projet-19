/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:36 by gcools            #+#    #+#             */
/*   Updated: 2023/11/06 17:00:50 by guillaumeco      ###   ########.fr       */
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
		if (ft_putchar_return('-', fd) == -1)
			return (-1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_return(n / 10, fd);
	}
	if (ft_putchar_return((n % 10) + '0', fd) == -1)
		return (-1);
	return (total);
}
