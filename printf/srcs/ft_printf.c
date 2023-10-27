/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:40:54 by gcools            #+#    #+#             */
/*   Updated: 2023/10/27 13:54:44 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	const char	*temp;
	const char	*str;

	va_start(args, string);
	temp = string;
	while (*temp != '\0')
	{
		if (*temp == '%')
		{
			temp++;
			if (*temp == 's')
			{
				str = va_arg(args, const char *);
				write(1, str, ft_strlen(str));
			}
		}
		else
		{
			write(1, temp, 1);
		}
		temp++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%s\n", "test");
	return (0);
}
