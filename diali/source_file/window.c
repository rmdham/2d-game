#include    "../includes/so_long.h"

int	exit_game(t_map *dt, char *s)
{
	perror(s);
	mlx_destroy_window(dt->mlx_ptr, dt->wind);
	exit(1);
}

int set_game(t_map *dt)
{
    int x;
    int y;

    x = 0;
    y = 0;
    dt->counter = 0;
    // collectibles_set(dt, x, y);
    dt->press = 0;
    dt->key = 5;
    dt->reached = 1;
    dt->moves = 0;
    dt->player_up = XPM(dt->mlx_ptr, "../assets/player_up.xpm", &x, &y);
    dt->player_up1 = XPM(dt->mlx_ptr, "../assets/player_up1.xpm", &x, &y);
    dt->player_rt = XPM(dt->mlx_ptr, "../assets/player_rt.xpm", &x, &y);
    dt->player_rt1 = XPM(dt->mlx_ptr, "../assets/player_rt1.xpm", &x, &y);
    dt->player_lf = XPM(dt->mlx_ptr, "../assets/player_lf.xpm", &x, &y);
    dt->player_lf1 = XPM(dt->mlx_ptr, "../assets/player_lf1.xpm", &x, &y);
    dt->player_dn = XPM(dt->mlx_ptr, "../assets/player_dn.xpm", &x, &y);
    dt->player_dn1 = XPM(dt->mlx_ptr, "../assets/player_dn1.xpm", &x, &y);
    dt->enemy = XPM(dt->mlx_ptr, "../assets/enemy.xpm", &x, &y);
    dt->enemy1 = XPM(dt->mlx_ptr, "../assets/enemy1.xpm", &x, &y);
    dt->collect = XPM(dt->mlx_ptr, "../assets/collect.xpm", &x, &y);
    dt->ground = XPM(dt->mlx_ptr, "../assets/ground.xpm", &x, &y);
    dt->wall = XPM(dt->mlx_ptr, "../assets/wall.xpm", &x, &y);
    dt->exit = XPM(dt->mlx_ptr, "../assets/exit.xpm", &x, &y);
    dt->exit1 = XPM(dt->mlx_ptr, "../assets/exit1.xpm", &x, &y);
    if  (!dt->player_up || !dt->player_up1 || !dt->player_rt || !dt->player_rt1 || \
            !dt->player_lf || !dt->player_lf1 || !dt->player_dn || !dt->player_dn1 || \
            !dt->enemy || !dt->enemy1 || !dt->collect || !dt->ground || !dt->wall || \
            !dt->exit || !dt->exit1)
        exit_game(dt, "failed to load images");
    return (1);
}
int draw_ground(t_map *dt)
{
    int x;
    int y;

    x = 0;
     while (x < dt->height)
    {
        y = 0;
        while (y < dt->width)
        {
            if (dt->maptiles[x][y] == '1')
                IMAGE(dt->mlx_ptr, dt->wind, dt->wall, y * 50, x * 50);
            else
                IMAGE(dt->mlx_ptr, dt->wind, dt->ground, y * 50, x * 50);
            y++;
        }
        x++;
    }
    return (1);
}
// int draw_game(t_map *dt)
// {
//     if (dt->moves == 0)
//     {
//         IMAGE(dt->mlx_ptr, dt->wind, dt->player_dn, dt->playerX * 50, dt->playerY * 50);
//     }
//     if (dt->key == W)
//     {
//         if (dt->press == 0)
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_up, dt->playerX * 50, dt->playerY * 50);
//         else
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_up1, dt->playerX * 50, dt->playerY * 50);
//     }
//     else if (dt->key == S)
//     {
//         if (dt->press == 0)
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_dn, dt->playerX * 50, dt->playerY * 50);
//         else
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_dn1, dt->playerX * 50, dt->playerY * 50);
//     }
//     else if (dt->key == A)
//     {
//         if (dt->press == 0)
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_lf, dt->playerX * 50, dt->playerY * 50);
//         else
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_lf1, dt->playerX * 50, dt->playerY * 50);
//     }
//     else if (dt->key == D)
//     {
//         if (dt->press == 0)
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_rt, dt->playerX * 50, dt->playerY * 50);
//         else
//             IMAGE(dt->mlx_ptr, dt->wind, dt->player_rt1, dt->playerX * 50, dt->playerY * 50);
//     }
//     player_anime(dt);
//     return (1);
// }

int	draw_game(t_map *d)
{
	d->x = 0;
	while (d->x < d->height)
	{
		d->y = 0;
		while (d->y < d->width)
		{
			if (d->maptiles[d->x][d->y] == '0')
				IMAGE(d->mlx_ptr, d->wind, d->ground, d->y * TW, d->x * TH);
			else if (d->maptiles[d->x][d->y] == '1')
				IMAGE(d->mlx_ptr, d->wind, d->wall, d->y * TW, d->x * TH);
			else if (d->maptiles[d->x][d->y] == 'E')
				IMAGE(d->mlx_ptr, d->wind, d->exit, d->y * TW, d->x * TH);
			else if (d->maptiles[d->x][d->y] == 'C')
            {
				IMAGE(d->mlx_ptr, d->wind, d->collect,d->y * TW, d->x * TH);
            }
			else if (d->maptiles[d->x][d->y] == 'X')
				IMAGE(d->mlx_ptr, d->wind, d->enemy, d->y * TW, d->x * TH);
			d->y++;
		}
		d->x++;
	}
	player_anime(d);
	return (1);
}

int 
set_player(t_map *dt)
{
    int x;
    int y;

    x = 0;
    while (x < dt->height)
    {
        y = 0;
        while (y < dt->width)
        {
            if (dt->maptiles[x][y] == 'P')
            {
                dt->playerX = y;
                dt->playerY = x;
                dt->maptiles[x][y] = '0';
                return (1);
            }
            y++;
        }
        x++;
    }
    dt->startX = dt->playerX;
    dt->startY = dt->playerY;
    return (0);    
}


int     window_init(t_map *dt)
{
    int wx;
    int wy;

    wx = dt->width * 50;
    wy = dt->height * 50;
    dt->mlx_ptr = mlx_init();
    dt->wind = WINDOW(dt->mlx_ptr, wx, wy, "So Long");
    if (!dt->mlx_ptr || !dt->wind)
        return (0);
    mlx_hook(dt->wind, ON_DESTROY, 0, exit_game, dt);
    // int return_ = set_game(dt);
    // printf("return_ = %d\n", return_);
    if (!set_game(dt))
        err_msg("game not set\n");
    if (!draw_ground(dt))
        err_msg("failed to draw ground\n");
    set_player(dt);
    mlx_hook(dt->wind, 2, 0, ft_key_hook, dt);
    mlx_loop_hook(dt->mlx_ptr, animation, dt);
    mlx_loop(dt->mlx_ptr);

    
    
    return (1);
}
