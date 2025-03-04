#include <fcntl.h>
#include <stdlib.h>

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
}                   t_map;

char    **addilmap(char **map, char *newline)
{
    int     i;
    int     size;
    char    **updatedmap;

    i = 0;
    size = 0; 
    while (map && map[size])
        size++;
    updatedmap = malloc(sizeof(char *) * (size + 2));
    if (!updatedmap)
        return (NULL);
    while (i < size)
    {
        updatedmap[i] =  map[i]
        i++;
    }
    updatedmap[i] = newline;
    updatedmap[i+1] = NULL;
    free(map);
    return (updatedmap);

}
}

int mvalidialmap(t_map *dt)

int main(int ac, char **av)
{
    t_map   dt;
    int     fd;
    char    *line;

    dt.maptiles == NULL;
    if ((ac != 2) || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
        return (err_msg("error arg or missing file"));
    fd = open(av[1], O_RDONLY);
    
    if (fd < 0)
        return (err_msg("failed to read the file!!"));
    line = get_next_line(fd);
    while (line)
    {
        dt.maptiles = addilmap(dt.maptiles, line);
        line = get_next_line(fd);
    }
    if (!dt.maptiles)
        return (err_msg("no map"));
    if (!mvalidialmap(&dt) || !check_row(&dt))
        return (err_msg("invalid map or row"));    
}