#ifndef     SO_LONG_H
# define    SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <fcntl.h>
# include <stddef.h>
#include <stdlib.h>
# include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define WINDOW mlx_new_window
#define IMAGE mlx_put_image_to_window
#define XPM mlx_xpm_file_to_image
#define ON_DESTROY 17
#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define TW 50
#define TH 50


typedef struct map
{
    void    *wind;
    void    *mlx_ptr;
    char    **maptiles;
    int     width;
    int     height;
    int     x;
    int     y; 
    int     Cplayer; 
    int     playerX;
    int     playerY;
    int     startX;
    int     startY;
    int     Exit;
    int     C;
    int     press;
    int     key;
    int     reached;
    int     moves;
    int     frame_counter;
    int     current_frame;  
    void    *player_up;
    void    *player_up1;
    void    *player_rt;
    void    *player_rt1;
    void    *player_lf;
    void    *player_lf1;
    void    *player_dn;
    void    *player_dn1;
    void    *enemy;
    void    *enemy1;
    void    *collect;
    void    *ground;
    void    *wall;
    void    *exit;
    void    *exit1;
    int     counter;

}           t_map;


int     err_msg(char *s);
int     mvalidialmap(t_map *dt);
char    **addilmap(char **map, char *newline);
int     mvalidiyinlwalls(char **map, t_map *dt);
int     mvalidyatri9(t_map *dt);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
size_t	count_word_str(long nb);
void	*allocation_str(size_t len);
char	*if_zero(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
int		ft_strchr(char *s, int c);
size_t  ft_strlen(char *s);
char	*ft_chyata(char *line_b_chyata);
char	*get_buffreadline(int fd, char *line);
char	*geti_line(char *line_b_chyata);
int     ft_atoi(const char *str);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	initializer(t_map *dt);
int     check_row(t_map *dt);
int     set_game(t_map *dt);
int     exit_game(t_map *dt, char *s);
int     window_init(t_map *dt);
int     draw_ground(t_map *dt);
int     ft_key_hook(int keycode, t_map *data);
void    ft_playermovement(int keycode, t_map *dt);
void    player_anime(t_map *dt);
void    anime_right(t_map *dt);
void    anime_left(t_map *dt);
void    anime_up(t_map *dt);
void    anime_down(t_map *dt);
int     draw_game(t_map *dt);
int	    animation(t_map *dt);
void	all_moves(int key, t_map *dt);



#endif




