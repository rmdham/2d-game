
#ifndef CUBE_3D_H
#define CUBE_3D_H


#include "../mlx/mlx.h"
# include <math.h>
# include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define PI 3.1415926535
# define PI2 PI/2
# define PI3 3*PI/2
# define RD 0.0174533
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307



typedef struct s_map
{
    char    **maptiles;
    double  px;
    double  py;
    double  last_px;
    double  last_py;
    double	delta_x;
	double	delta_y;
	double	pa;
    void    *win;
    void    *ptr;
    void    *img;
    char    *addr;
    int		bits_per_pixel;
	int     line_length;
	int     endian;
}t_map;