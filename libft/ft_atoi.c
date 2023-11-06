/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:33:02 by guillaumeco       #+#    #+#             */
/*   Updated: 2023/11/04 00:01:43 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	compt;
	int	final;

	i = 0;
	compt = 1;
	final = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		compt = compt * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10;
		final = final + (str[i] - 48);
		i++;
	}
	return (final * compt);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("   21474836470000000000"));
	printf("%d\n", atoi("   21474836470000000000"));
	return (0);
}
*/
