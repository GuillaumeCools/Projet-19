/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:13 by gcools            #+#    #+#             */
/*   Updated: 2024/03/12 14:26:10 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive_message(int c)
{
	static int	i;
	static int	stock;

	//masque binaire pour faire des shifts
	//on recup que des 1 parce que stock = 0
	//stock :           00000001
	//ce qu on recoit : 00000001
	//si ce qu on recoit est un 1 on le stock et on passe a la suite 
	//jusqu a ce que ca fasse 8 bite et donc un caractere
	
	if (c == SIGUSR1)
		stock |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", stock);
		i = 0;
		stock = 0;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("%s\n", "Error");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_receive_message);
		signal(SIGUSR2, ft_receive_message);
		pause();
	}
	return (0);
}
