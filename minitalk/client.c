/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:52:47 by gcools            #+#    #+#             */
/*   Updated: 2024/03/12 14:32:23 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					compt;
	unsigned long long	final;

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
		final = (final * 10) + (str[i] - 48);
		i++;
	}
	return (final * compt);
}

void	ft_send_message(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)))
			kill(pid, SIGUSR1);
		// on compare les 8 bites du caractere qu on veut envoyer : 00000000
		// avec le 1 :												00000001
		// et quand les deux sont les memes on envoit SIGUSR1 (1) -> ils sont les memes quand un des huits bites est egal a 1
		// sinon on envoie SIUSR2 (0)
		
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("%s\n", "Error, the PID must be superior to 0");
			return (1);
		}
		while (argv[2][i] != '\0')
		{
			ft_send_message(pid, argv[2][i]);
			i++;
		}
		ft_send_message(pid, '\n');
	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
