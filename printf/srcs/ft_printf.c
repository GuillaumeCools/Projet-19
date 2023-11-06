/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/11/03 15:57:34 by guillaumeco      ###   ########.fr       */
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

int	ft_check(const char *temp, va_list args)
{
	if (*temp == 'c')
		return (ft_putchar_fd((va_arg(args, int)), 1));
	if (*temp == 's')
		return (ft_putstr_return(va_arg(args, char *), 1));
	if (*temp == 'p')
	{
		write (1, "0x10", 4);
		return (ft_putnbr_hex((va_arg(args, int)), 1));
	}
	if (*temp == 'd')
		return (ft_putnbr_fd((va_arg(args, int)), 1));
	if (*temp == 'i')
		return (ft_putnbr_fd((va_arg(args, int)), 1));
	if (*temp == 'u')
		return (ft_putnbr_pos_fd((va_arg(args, int)), 1));
	if (*temp == 'x')
		return (ft_num_to_hex((va_arg(args, int)), 1));
	if (*temp == 'X')
		return (ft_num_to_hex_up((va_arg(args, int)), 1));
	if (*temp == '%')
	{
		va_arg(args, char *);
		ft_putchar_fd('%', 1);
	}
}

int	ft_advance(va_list args, const char *string)
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
				return (ft_check(temp, args));
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
	int	temp;

	va_start(args, string);
	temp = ft_advance(args, string);
	va_end(args);
	return (temp);
}

int	main(void)
{
	printf("%d\n", printf("%d\n", 9));
	ft_printf("%d\n", ft_printf("%d", 9));
	return (0);
}


//mettre toutes les variables en int a la place de void pour return la bonne valeur 
//calculer la valeur de retours en modifiant des fonctions 