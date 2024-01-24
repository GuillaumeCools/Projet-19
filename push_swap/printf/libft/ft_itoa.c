/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:08:56 by gcools            #+#    #+#             */
/*   Updated: 2023/10/26 10:56:49 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*final;
	long	long_num;

	len = ft_intlen(n);
	final = (char *)malloc(sizeof(char) * len + 1);
	if (!final)
		return (NULL);
	if (n == 0)
		final[0] = '0';
	long_num = n;
	final[len--] = '\0';
	if (long_num < 0)
	{
		final[0] = '-';
		long_num = -long_num;
	}
	while (long_num > 0)
	{
		final[len--] = '0' + (long_num % 10);
		long_num = long_num / 10;
	}
	return (final);
}
/*
int	main(void)
{
	int	n;

	n = 0;
	printf("%s\n", ft_itoa(n));
	return (0);
}
*/
