/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/10/31 14:31:26 by gcools           ###   ########.fr       */
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

void	ft_putnbr_hex(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 16)
		ft_putnbr_hex(n / 16, fd);
	if (n < 10)
		ft_putchar_fd((n % 16) + '0', fd);
	else
		ft_putchar_fd((n - 10 + 'a'), fd);
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
	write (1, "0x", 2);
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
	printf("%p\n", "test");
	ft_printf("%p", "test");
	return (0);
}
