  #include    "../includes/so_long.h"

// int key_hook(int keycode, s_mlx_data *data)
// {
//     if (keycode == 53)
//     {
//         printf("the %d key (ESC) has been pressed\n\n", keycode);
//         mlx_destroy_window(data->mlx_inst, data->wind);
//         free(data->mlx_inst);
//         exit(1);
//     }
//     printf("the %d key has been pressed\n\n", keycode);
//     return (0);
// }

// int main(void)
// {
//     s_mlx_data  data;
 
//  data.mlx_inst = mlx_init();
//  if (NULL == data.mlx_inst)
//     return (1);
// data.wind = mlx_new_window(data.mlx_inst, 500, 1000, "So Long");
// if (NULL == data.wind)
// {
//     mlx_destroy_window(data.mlx_inst,data.wind);
//     free(data.mlx_inst);
//     return  (1);
// }
// mlx_key_hook(data.wind,key_hook, &data);
// int y = 1000 ;
// while (y < 1000 -50)
// {
//     int x = 50;
//     while (x < 500 - 50)
//     {
//         mlx_pixel_put(data.mlx_inst, data.wind, x, y , rand() % 0x1000000);
//         x++;
//     }
//     y++;
// }
// mlx_loop(data.mlx_inst);
// mlx_destroy_window(data.mlx_inst, data.wind);
// free(data.mlx_inst);

// }


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
        return  (err_msg("noooo maaap pls tryy again"));
    printf("the map is %s\n", argv[1]);
    fd = open(argv[1],O_RDONLY);
    if (fd < 0)
        return  (err_msg("failed to open"));
    printf("fd is %d\n", fd);
    line = get_next_line(fd);
    while (line)
    {
        dt.maptiles = addilmap(dt.maptiles, line);
        line = get_next_line(fd);
    }
    for (int i = 0; dt.maptiles[i]; i++)
        printf("%zu\n", strlen(dt.maptiles[i]));

    if (!mvalidialmap(&dt) || !check_row(&dt))
        return (err_msg("errrrreuuur"));
}
