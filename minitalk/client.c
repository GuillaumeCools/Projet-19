/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:52:47 by gcools            #+#    #+#             */
/*   Updated: 2023/12/08 16:06:30 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

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

void	ft_send_message(int pid, char c)
{

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
			printf("%s\n", "Error, the PID must be superior to 0");
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
	{
		printf("%s\n", "Error");
	}
	return (0);
}
