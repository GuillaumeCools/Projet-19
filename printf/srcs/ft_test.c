/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/10/30 15:23:05 by gcools           ###   ########.fr       */
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

void	ft_create_s(va_list args)
{
	char	*result;

	result = va_arg(args, char *);
	ft_putstr_fd(result, 1);
}

void	ft_create_d(va_list args)
{
	int	result;

	result = (int)(va_arg(args, char *));
	ft_putnbr_fd(result, 1);
}

void	ft_create_c(va_list args)
{
	char	result;

	result = (char)va_arg(args, char *);
	ft_putchar_fd(result, 1);
}

void	ft_check(va_list args, const char *string)
{
	const char	*temp;
	int			i;

	i = 0;
	temp = string;
	while (*temp != '\0')
	{
		while (i < ft_tab_count(string))
		{
			if (*temp == '%')
			{
				temp++;
				if (*temp == 's')
					ft_create_s(args);
				if (*temp == 'd')
					ft_create_d(args);
				if (*temp == 'c')
					ft_create_c(args);
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
	ft_check(args, string);
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("Res : %s %s", "test" "ok");
	return (0);
}
