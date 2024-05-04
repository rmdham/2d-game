#include    "../includes/so_long.h"

void	anime_right(t_map *dt)
{
	static int	j;

	if (j <= 0)
		j = 50;
	j -= 5;
	if (dt->frame_counter % 2 == 0)
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->player_rt, \
			(dt->playerX * TW + 0) - j, \
			dt->playerY * TH );
	}
	else
	{
		IMAGE(dt->mlx_ptr, dt->wind, dt->player_rt1, \
			(dt->playerX * TW + 0) - j, \
			dt->playerY * TH );
	}
	if (j <= 0)
	{
		dt->press = 0;
		dt->reached = 1;
		j = 0;
	}
}
void    anime_left(t_map *dt)
{
    static int	j;

    if (j <= 0)
        j = 50;
    j -= 5;
    if (dt->frame_counter % 2 == 0)
    {
        IMAGE(dt->mlx_ptr, dt->wind, dt->player_lf, \
            (dt->playerX * TW ) + j, \
            dt->playerY * TH );
    }
    else
    {
        IMAGE(dt->mlx_ptr, dt->wind, dt->player_lf1, \
            (dt->playerX * TW ) + j, \
            dt->playerY * TH +0);
    }
    if (j <= 0)
    {
        dt->press = 0;
        dt->reached = 1;
        j = 0;
    }
}
void    anime_up(t_map *dt)
{
    static int	j;

    if (j <= 0)
        j = 50;
    j -= 5;
    if (dt->frame_counter % 2 == 0)
    {
        IMAGE(dt->mlx_ptr, dt->wind, dt->player_up, \
            dt->playerX * TW + 0, \
            (dt->playerY * TH + 0) + j);
    }
    else
    {
        IMAGE(dt->mlx_ptr, dt->wind, dt->player_up1, \
            dt->playerX * TW + 0, \
            (dt->playerY * TH + 0) + j);
    }
    if (j <= 0)
    {
        dt->press = 0;
        dt->reached = 1;
        j = 0;
    }
}

void    anime_down(t_map *dt)
{
    static int	j;

    if (j <= 0)
        j = 50;
    j -= 5;
    if (dt->frame_counter % 2 == 0)
    {
        IMAGE(dt->mlx_ptr, dt->wind, dt->player_dn, \
            dt->playerX * TW + 0, \
            (dt->playerY * TH + 0) - j);
    }
    else
    {
        IMAGE(dt->mlx_ptr, dt->wind, dt->player_dn1, \
            dt->playerX * TW + 0, \
            (dt->playerY * TH + 0) - j);
    }
    if (j <= 0)
    {
        dt->press = 0;
        dt->reached = 1;
        j = 0;
    }
}





void    player_anime(t_map *dt)
{
	if (!dt->press && dt->key == D)
		IMAGE(dt->mlx_ptr, dt->wind, dt->player_rt, (dt->playerX * \
			TW), dt->playerY * TH);
	if (!dt->press && dt->key == A)
		IMAGE(dt->mlx_ptr, dt->wind, dt->player_lf, (dt->playerX * \
			TW + 0), dt->playerY * TH + 0);
	if (!dt->press && dt->key == W)
		IMAGE(dt->mlx_ptr, dt->wind, dt->player_up, (dt->playerX * \
			TW + 0), dt->playerY * TH + 0);
	if (!dt->press && dt->key == S)
		IMAGE(dt->mlx_ptr, dt->wind, dt->player_dn, (dt->playerX * \
			TW + 0), dt->playerY * TH + 0);
	else if (dt->press && dt->key == D)
		anime_right(dt);
	else if (dt->press && dt->key == A)
		anime_left(dt);
	else if (dt->press && dt->key == W)
		anime_up(dt);
	else if (dt->press && dt->key == S)
		anime_down(dt);
}
