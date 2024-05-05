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

typedef struct mlx_data
{
    void *wind;
    void *mlx_inst;
}           s_mlx_data;

typedef struct map
{
    char **maptiles;
    int width;
    int height;
    int x;
    int y; 
    int c_player; 
    int player_x;
    int player_y;
    int exit;
    int c;
}           t_map;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int     err_msg(char *s);
int     mvalidialmap(t_map *dt);
char    **addilmap(char **map, char *newline);
int     mvalidiyinlwalls(char **map, t_map *dt);
int     mvalidyatri9(t_map *dt);
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

int		found_newline(t_list *list);
t_list	*find_lst_node(t_list *list);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	polish_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);



#endif




