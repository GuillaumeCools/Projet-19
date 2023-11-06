/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pos_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:16:26 by gcools            #+#    #+#             */
/*   Updated: 2023/11/06 16:59:54 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	ft_putnbr_pos_return(unsigned int n, int fd)
{
	int	total;

	total = ft_intlen_pos(n);
	if (n >= 10)
	{
		ft_putnbr_pos_return(n / 10, fd);
	}
	if (ft_putchar_return((n % 10) + '0', fd) == -1)
		return (-1);
	return (total);
}
