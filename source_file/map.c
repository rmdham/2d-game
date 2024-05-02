#include    "../includes/so_long.h"

int check_row(t_map *dt)
{
    int i;
    size_t len;

    for (int j = 0; dt->maptiles[j]; j++)
        printf("%s\n", dt->maptiles[j]);
    len = strlen(dt->maptiles[0]);
    i = 0;
    while   (dt->maptiles[i])
    {
        printf("len is %zu\n", len);
        if (strlen(dt->maptiles[i]) != len)
        {
            printf("manza\n");
            return (0);
        }
        i++;
    }
    return (1);
}

char    **addilmap(char **map, char *newline)
{
    int     i;
    int     size;
    char    **updatedmap;

    i=0;
    size=0;
    while (map && map[size])
        size++;
    updatedmap = malloc(sizeof(char *) * (size + 2));
    if (!updatedmap)
        return (NULL);
    while (i < size)
    {
        updatedmap[i] = map[i];
        i++; 
    }
    updatedmap[i] = newline;
    updatedmap[i + 1] = NULL;
    free(map);
    return (updatedmap);
}

int mvalidiyinlwalls(char **map, t_map *dt)
{
    int i;
    int size;

    size = 0;
    while (map[size])
        size++;
    i = 0;
    while (map[0][i] && map[size - 1][i])
    {
        if (map[0][i] != '1' || map[size - 1][i] != '1')
            return (1);
        i++;
    }
    dt->width = i;
    i = 0;
    while (i < size)
    {
        if (map[i][0] != '1' || map[i][ft_strlen(map[0])-1] != '1')
            return  (1);
        i++;
    }
    dt->height = i;
    return  (0);
}
  
  
  int	dfs(t_map *data, int x, int y, int **visited)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width || \
			data->maptiles[x][y] == '1' || visited[x][y])
		return (0);
	if (data->maptiles[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (dfs(data, x + 1, y, visited) || dfs(data, x - 1, y, visited) || \
			dfs(data, x, y + 1, visited) || dfs(data, x, y - 1, visited))
		return (1);
	return (0);
}


int mvalidyatri9(t_map *dt)

{
    int i;
    int j;
    int result;
    int **visited;

    visited = malloc(sizeof(int *) * dt->height);
    if (!visited)
        return (0);
    i = 0;
    while (i < dt->height)
    {
        visited[i] = malloc(sizeof(int) * dt->width);
        if (!visited[i])
            return (0);
        j = 0;
        while (j < dt->width)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    result = dfs(dt, dt->playerX, dt->playerY, visited);
    i = 0;
    while (i < dt->height)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
    return (result);
}


int mvalidialmap(t_map *dt)
{
    initializer(dt);
    while (dt->maptiles[dt->x])
    {
        dt->y = 0;
        while (dt->maptiles[dt->x][dt->y])
        {
            if (dt->maptiles[dt->x][dt->y] == 'P')
            {
                dt->Cplayer++;
                dt->playerX = dt->x;
                dt->playerY = dt->y;
            }
            else if (dt->maptiles[dt->x][dt->y] == 'E')
                dt->Exit++;
            else if (dt->maptiles[dt->x][dt->y] == 'C')
                dt->C++;
            dt->y++;
        }
        dt->x++;
    }
    if (dt->Cplayer != 1 || dt->Exit != 1 || dt->C < 1 || \
			!mvalidiyinlwalls(dt->maptiles, dt) || \
			!mvalidyatri9(dt))
{
        return (1);
}
    return  (0);
}