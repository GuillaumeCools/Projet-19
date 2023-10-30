/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:40:54 by gcools            #+#    #+#             */
/*   Updated: 2023/10/30 11:50:04 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_s(va_list args)
{
	const char	*str;

	str = va_arg(args, const char *);
	write (1, str, ft_strlen(str));
}

void	ft_d(va_list args)
{
	int	str;

	str = ft_atoi(va_arg(args, const char *));
	ft_putnbr_fd(str, 1);
}

void	ft_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, const char *);
	write (1, &c, 1);
}

int	ft_printf(const char *string, ...)
{
	va_list		args;
	const char	*temp;

	va_start(args, string);
	temp = string;
	while (*temp != '\0')
	{
		if (*temp == '%')
		{
			temp++;
			if (*temp == 's')
				ft_s(args);
			if (*temp == 'd')
				ft_d(args);
			if (*temp == 'c')
				ft_c(args);
		}
		else
			write(1, temp, 1);
		temp++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%s\n %d\n", "test", "123");
	return (0);
}
