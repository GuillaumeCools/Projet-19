/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:13 by gcools            #+#    #+#             */
/*   Updated: 2023/12/18 10:32:46 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receive_message(int c)
{
	static int	bit;
	static int	i;

	if (c == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
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
