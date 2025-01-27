/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:48:29 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:52:49 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "ftprintf/ft_printf.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_player
{
	int				pi;
	int				pj;
}					t_player;

typedef struct t_exit
{
	int				ei;
	int				ej;
	int				visited;
}					t_exit;

typedef struct s_map
{
	int				wall;
	int				empty;
	int				collectible;
	int				exit;
	int				error;
	int				player;
	int				visited;
}					t_map;

typedef struct s_short
{
	int				dist;
	int				rear;
	int				cur_x;
	int				cur_y;
}					t_short;

typedef struct s_game
{
    void		*win;
    void		*img;
    void		*img_wall;
    void		*img_empty;
    void		*img_collectible;
    void	    *img_exit;
    void		*img_player;
	void			*mlx;
	int				collectibles;
	int				tilesize;
	int				win_width;
	int				win_height;
	int				rows;
	int				cols;
	int				big;
	int				lastc;
	int				shortest;
	int				moves;
	int				action;
	t_short			sp;
	t_map			**map;
	t_player		player;
	t_exit			exit;
}					t_game;

void				invalid_map(void);
void				no_path(t_game *game);
void				initialization_fail(t_game *game);
void				malloc_failed(void);
void				wrong_n_argu(void);
void				open_file(int *fd, char *map);
int					map_size(int *row, int *col, char *map, int byteread);
int					map_chars(char *map);
int					map_walls(char *map, int row, int col);
int					fillmap(t_map **map, char *argv, t_game *game);
int					valid_path(t_game *game);
void				freemap(t_game *game);
void				delete_imgs(t_game *game);
void				*start_game(t_game *game);
void				close_game(t_game *game);
int					press_x(t_game *game);
void				win_game(t_game *game);
void				lose_game(t_game *game);
int					load_png(t_game *game);
int					keyhook(int keycode, void *param);
void				moving_keys(t_game *game, int keycode);
void				drawmap_big(t_game *game);
void				drawmap(t_game *game);
void				short_path(t_game *game, int front);
void				change_struct_flags(t_game *game, int pi);
void				change_struct_flags_2(t_game *game, int pj);

#endif
