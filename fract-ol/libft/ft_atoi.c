/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:33:02 by guillaumeco       #+#    #+#             */
/*   Updated: 2024/06/11 14:10:24 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_check(unsigned long long final, unsigned long long final_temp,
					int compt)
{
	if (final < final_temp && compt == -1)
		return (0);
	if (final < final_temp)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					compt;
	unsigned long long	final;
	unsigned long long	final_temp;

	i = 0;
	compt = 1;
	final = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			compt = compt * -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		final_temp = final;
		final = (final * 10) + (str[i] - 48);
		if (final < final_temp)
			return (ft_check(final, final_temp, compt));
		i++;
	}
	return (final * compt);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("18446744073709551616"));
	printf("%d\n", atoi("18446744073709551616"));
	return (0);
}
*/
