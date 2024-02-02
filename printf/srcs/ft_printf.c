/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/12/11 16:35:41 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	ft_check(const char *temp, va_list args)
{
	if (*temp == 'c')
		return (ft_putchar_return((va_arg(args, int)), 1));
	if (*temp == 's')
		return (ft_putstr_return(va_arg(args, char *), 1));
	if (*temp == 'p')
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		return (ft_putnbr_hex_return((va_arg(args, uintptr_t)), 1) + 2);
	}
	if (*temp == 'd')
		return (ft_putnbr_return((va_arg(args, int)), 1));
	if (*temp == 'i')
		return (ft_putnbr_return((va_arg(args, int)), 1));
	if (*temp == 'u')
		return (ft_putnbr_pos_return((va_arg(args, unsigned int)), 1));
	if (*temp == 'x')
		return (ft_num_to_hex_return((va_arg(args, unsigned int)), 1));
	if (*temp == 'X')
		return (ft_num_to_hex_up_return((va_arg(args, unsigned int)), 1));
	if (*temp == '%')
		return (ft_putchar_return('%', 1));
	return (0);
}

int	ft_advance(va_list args, const char *string)
{
	int	total;
	int	total_temp;
	int	i;

	total = 0;
	i = 0;
	while (string[i] != '\0')
	{
		total_temp = total;
		if (string[i] != '%')
		{
			if (ft_putchar_return(string[i], 1) == -1)
				return (-1);
			total++;
		}
		else if (string[i] == '%' && string[i + 1])
		{
			i++;
			total += ft_check(&string[i], args);
			if (total < total_temp)
				return (-1);
		}
		i++;
	}
	return (total);
}

int	ft_printf(const char *string, ...)
{
	va_list		args;
	int			temp;

	va_start(args, string);
	temp = ft_advance(args, string);
	va_end(args);
	return (temp);
}
/*
int	main(void)
{
	//void	*ptr = ((void *)-14523);

	printf("%d\n", printf("%p\n", "test"));
	ft_printf("%d\n", ft_printf("%p\n", "test"));
	return (0);
}
*/
