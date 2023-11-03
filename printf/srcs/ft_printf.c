/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 15:06:32 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	ft_tab_count(const char *string)
{
	int	i;

	i = 0;
	while (*string != '\0')
	{
		if (*string == '%')
		{
			i++;
			string++;
		}
		string++;
	}
	return (i);
}

void	ft_check(const char *temp, va_list args)
{
	if (*temp == 'c')
		ft_putchar_fd((va_arg(args, int)), 1);
	if (*temp == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (*temp == 'p')
	{
		write (1, "0x10", 4);
		ft_putnbr_hex((va_arg(args, int)), 1);
	}
	if (*temp == 'd')
		ft_putnbr_fd((va_arg(args, int)), 1);
	if (*temp == 'i')
		ft_putnbr_fd((va_arg(args, int)), 1);
	if (*temp == 'u')
		ft_putnbr_pos_fd((va_arg(args, int)), 1);
	if (*temp == 'x')
		ft_num_to_hex((va_arg(args, int)), 1);
	if (*temp == 'X')
		ft_num_to_hex_up((va_arg(args, int)), 1);
	if (*temp == '%')
	{
		va_arg(args, char *);
		ft_putchar_fd('%', 1);
	}
}

void	ft_advance(va_list args, const char *string)
{
	const char	*temp;
	int			i;

	i = 0;
	temp = string;
	while (*temp != '\0')
	{
		while (i < ft_tab_count(string))
		{
			if (*temp != '%')
				ft_putchar_fd(*temp, 1);
			if (*temp == '%')
			{
				temp++;
				ft_check(temp, args);
				va_arg(args, char *);
				i++;
			}
			temp++;
		}
	}
}

int	ft_printf(const char *string, ...)
{
	va_list		args;

	va_start(args, string);
	ft_advance(args, string);
	va_end(args);
	return (0);
}

int	main(void)
{
	printf("%d\n", printf("%d\n", 9));
	ft_printf("%d\n", ft_printf("%d", 9));
	return (0);
}


