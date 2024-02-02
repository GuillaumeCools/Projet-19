/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:23:39 by gcools            #+#    #+#             */
/*   Updated: 2024/02/02 14:25:10 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window((data)->mlx, (data)->window);
	free((data)->mlx);
	exit (0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 600, 400, "Hello world!");
	mlx_hook(data.window, 17, (1L<<17), &on_destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}
