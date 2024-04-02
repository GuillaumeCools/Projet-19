/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:06:51 by gcools            #+#    #+#             */
/*   Updated: 2023/12/05 14:40:48 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
//# include "libft/libft.h"
# include <stdio.h> // A retirer
# include <math.h>
# include "X.h"
# include "keysym.h"
# include <stdlib.h>
# include <unistd.h>


#define ERROR_MESSAGE "Please choose between \n\t\"./a.out mandelbrot\" or \n\t\"./a.out julia <first value> <second value>\"\n"
// Defini la taille de la window
#define WIDTH	800
#define HEIGHT	800

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct s_complex
{
	//	real
	double	x;
	//	imaginary
	double	y;
}	t_complex;


typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp; // byte per pixels
	int		endian;
	int		line_len;
}	t_img;


typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window()

	t_img	img;

	//Hooks
	double	escape_value;
	int		iterations_definition; //more its big, more the quality will be good
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

//  Proto

//  strings utils
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
double	atoldbl(char *s);

// init
void	fractal_init(t_fractal *fractal);

// render
void	fractal_render(t_fractal *fractal);

// math
double 		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// hooks_events
int	key_handler(int keysym, t_fractal *fractal);
int	mouse_handler(int button, t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);

// clean
int	close_handler(t_fractal *fractal);

#endif