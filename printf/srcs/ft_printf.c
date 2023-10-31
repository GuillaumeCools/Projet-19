/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:39 by gcools            #+#    #+#             */
/*   Updated: 2023/10/31 10:19:14 by guillaumeco      ###   ########.fr       */
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
	ft_putstr_fd(va_arg(args, char *), 1);
}

void	ft_create_d(va_list args)
{
	ft_putnbr_fd((va_arg(args, int)), 1);
}

void	ft_create_c(va_list args)
{
	ft_putchar_fd(*(va_arg(args, char *)), 1);
}

void	ft_check(const char *temp, va_list args)
{
	if (*temp == 's')
		ft_create_s(args);
	if (*temp == 'd')
		ft_create_d(args);
	if (*temp == 'c')
		ft_create_c(args);
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
			
			// faire une fonction qui check pour chacune des possibilitées pour eviter de depasser les 25 lignes \/
			// implementer toutes les 8 types differents 
			// separer les differentes focntions en plusieurs fichier pour une arbo clean 
			
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
	//printf("%d\n", 1234);
	ft_printf("Bonjour :%s %d %c", "test", 1234, "c");
	return (0);
}
