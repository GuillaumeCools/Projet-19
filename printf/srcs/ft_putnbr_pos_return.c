/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pos_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:16:26 by gcools            #+#    #+#             */
/*   Updated: 2023/11/07 12:01:48 by gcools           ###   ########.fr       */
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
		if (ft_putnbr_pos_return(n / 10, fd) == -1)
			return (-1);
	}
	if (ft_putchar_return((n % 10) + '0', fd) == -1)
		return (-1);
	return (total);
}
