/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 02:47:42 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

void	ft_putnbr_pos_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_hex(uintptr_t n, int fd)	//regarder pour les 2/3 premiers nombre apres le OX
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

void	ft_num_to_HEX(int n, int fd)
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
		ft_num_to_HEX(n / 16, fd);
	ft_putchar_fd(hex_base[n % 16], fd);
}

void	ft_create_c(va_list args)
{
	ft_putchar_fd(*(va_arg(args, char *)), 1);
}

void	ft_create_s(va_list args)
{
	ft_putstr_fd(va_arg(args, char *), 1);
}

void	ft_create_p(va_list args)
{
	write (1, "0x10", 4);
	ft_putnbr_hex((va_arg(args, int)), 1);
}

void	ft_create_d(va_list args)
{
	ft_putnbr_fd((va_arg(args, int)), 1);
}

void	ft_create_i(va_list args)
{
	ft_putnbr_fd((va_arg(args, int)), 1);
}

void	ft_create_u(va_list args)
{
	ft_putnbr_pos_fd((va_arg(args, int)), 1);
}

void	ft_create_x(va_list args)
{
	ft_num_to_hex((va_arg(args, int)), 1);
}

void	ft_create_X(va_list args)
{
	ft_num_to_HEX((va_arg(args, int)), 1);
}

void	ft_create_pourcent(va_list args)
{
	va_arg(args, char *);
	ft_putchar_fd('%', 1);
}

void	ft_check(const char *temp, va_list args)
{
	if (*temp == 'c')
		ft_create_c(args);
	if (*temp == 's')
		ft_create_s(args);
	if (*temp == 'p')
		ft_create_p(args);
	if (*temp == 'd')
		ft_create_d(args);
	if (*temp == 'i')
		ft_create_i(args);
	if (*temp == 'u')
		ft_create_u(args);
	if (*temp == 'x')
		ft_create_x(args);
	if (*temp == 'X')
		ft_create_X(args);
	if (*temp == '%')
		ft_create_pourcent(args);
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
	printf("%p\n", "54353583");
	ft_printf("%p", "54353583");
	return (0);
}
