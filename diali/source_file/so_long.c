  #include    "../includes/so_long.h"
void	move_right(t_map *dt)
{
	dt->playerX++;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = D;
}
void	move_left(t_map *dt)
{
	dt->playerX--;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = A;
}
void	move_up(t_map *dt)
{
	dt->playerY--;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = W;
}
void	move_down(t_map *dt)
{
	dt->playerY++;
	dt->moves++;
	dt->press = 1;
	dt->reached = 0;
	dt->key = S;
}


void	all_moves(int key, t_map *dt)
{
	if (key == D)
		move_right(dt);
	else if (key == A)
		move_left(dt);
	else if (key == W)
		move_up(dt);
	else if (key == S)
		move_down(dt);
}

void    ft_playermovement(int keycode, t_map *dt)
{
	int	old_x;
	int	old_y;
	(void)keycode;

	old_x = dt->playerX;
	old_y = dt->playerY;
	all_moves(keycode, dt);
	if (dt->playerX < 0 || dt->playerX >= dt->width || dt->playerY < 0 || \
		dt->playerY >= dt->height || dt->maptiles[dt->playerY][dt->playerX] == '1')
	{
		dt->playerX = old_x;
		dt->playerY = old_y;
	}
	else if (dt->maptiles[dt->playerY][dt->playerX] == 'X')
		exit_game(dt, "You Lose");
	else if (dt->maptiles[dt->playerY][dt->playerX] == 'C')
	{
		dt->collect--;
		dt->maptiles[dt->playerY][dt->playerX] = '0';
		draw_ground(dt);
	}
	else if (dt->maptiles[dt->playerY][dt->playerX] == 'E' &&
				dt->collect == 0)
		exit_game(dt, "You Won");
	draw_ground(dt);
	draw_game(dt);
}

int ft_key_hook(int keycode, t_map *dt)
{
	if (dt->reached == 1)
	{
		if (keycode == W && dt->maptiles[dt->playerY - 1][dt->playerX] != '1')
			ft_playermovement(W, dt);
		else if (keycode == S && dt->maptiles[dt->playerY + 1][dt->playerX] != '1')
			ft_playermovement(S, dt);
		else if (keycode == A && dt->maptiles[dt->playerY][dt->playerX - 1] != '1')
			ft_playermovement(A, dt);
		else if (keycode == D && dt->maptiles[dt->playerY][dt->playerX + 1] != '1')
			ft_playermovement(D, dt);
		printf("Moves : %d\n", dt->moves);
	}
	if (keycode == ESC)
		exit_game(dt, "You Exited Game");
	return (0);
}

int	animation(t_map *dt)
{
	char	*n;

	n = ft_itoa(dt->moves);
	dt->frame_counter++;
	draw_game(dt);
	mlx_string_put(dt->mlx_ptr, dt->wind, 50, 50, 0xFFFF00, "Moves Number : ");
	mlx_string_put(dt->mlx_ptr, dt->wind, 210, 50, 0xFFFF00, \
						ft_itoa(dt->moves));
	free(n);
	return (0);
}



int	error_mssg(char *s )
{
	perror(s);
	return (1);
}

int main(int argc, char **argv)
{
    t_map   dt;
    int     fd;
    char    *line;

    dt.maptiles = NULL;
    if ((argc != 2) || !ft_strnstr(argv[1], ".ber",ft_strlen(argv[1])))
        return  (err_msg("arg error or missin file"));
    fd = open(argv[1],O_RDONLY);
    if (fd < 0)
        return  (err_msg("failed to open"));
    line = get_next_line(fd);
    while (line)
    {
        dt.maptiles = addilmap(dt.maptiles, line);
        line = get_next_line(fd);
    }
    if (!dt.maptiles)
        return  (err_msg("no map"));
    if (!mvalidialmap(&dt) || !check_row(&dt))
        return (err_msg("invalid map or row"));
    if (!window_init(&dt))
        return (err_msg("failed to init window"));
    free(dt.maptiles);
    close(fd);
    return (0);
}
