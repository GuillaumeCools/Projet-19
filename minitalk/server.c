/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:13 by gcools            #+#    #+#             */
/*   Updated: 2023/12/08 15:46:17 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	ft_receive_message(char c)
{
	
}

int	main(int argc, char **argv)
{
	int		pid;

	(void)argv;
	if (argc != 1)
	{
		printf("%s\n", "Error");
		return (1);
	}
	pid = getpid();
	printf("PID: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_receive_message);
		signal(SIGUSR1, ft_receive_message);
		pause();
	}
	return (0);
}
